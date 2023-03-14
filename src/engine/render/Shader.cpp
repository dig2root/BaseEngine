#include "engine/render/Shader.h"

#include "engine/GLErrorManager.h"

#include <fstream>
#include <sstream>


void Shader::createShader()
{
	GLCall(m_programID = glCreateProgram());

	m_vertexShaderID = compileShader(GL_VERTEX_SHADER, m_vertexShaderSource);
	m_fragmentShaderID = compileShader(GL_FRAGMENT_SHADER, m_fragmentShaderSource);
	
	GLCall(glAttachShader(m_programID, m_vertexShaderID));
	GLCall(glAttachShader(m_programID, m_fragmentShaderID));
	
	link();

	GLCall(glDeleteShader(m_vertexShaderID));
	GLCall(glDeleteShader(m_fragmentShaderID));
}

void Shader::parseShader(const std::string& filepath)
{
	std::ifstream stream(filepath);

	if (!stream.is_open()) {
		std::cout << "Failed to open file: " << filepath << std::endl;
		return;
	}

	enum class ShaderType {
		NONE = -1, VERTEX = 0, FRAGMENT = 1
	};

	std::string line;
	std::stringstream ss[2];
	ShaderType type = ShaderType::NONE;
	while (getline(stream, line)) {
		if (line.find("#shader") != std::string::npos) {
			if (line.find("vertex") != std::string::npos) {
				type = ShaderType::VERTEX;
			}
			else if (line.find("fragment") != std::string::npos) {
				type = ShaderType::FRAGMENT;
			}
		}
		else {
			ss[(int)type] << line << '\n';
		}
	}

	m_vertexShaderSource = ss[0].str();
	m_fragmentShaderSource = ss[1].str();
}

GLuint Shader::compileShader(GLuint type, const std::string& source)
{
	GLCall(GLuint id = glCreateShader(type));
	const char* src = source.c_str();
	GLCall(glShaderSource(id, 1, &src, nullptr));
	GLCall(glCompileShader(id));

	int result;
	GLCall(glGetShaderiv(id, GL_COMPILE_STATUS, &result));
	if (result == GL_FALSE) {
		int length;
		GLCall(glGetShaderiv(id, GL_INFO_LOG_LENGTH, &length));
		char* message = (char*)_malloca(length * sizeof(char));
		GLCall(glGetShaderInfoLog(id, length, &length, message));
		std::cout << "Failed to compile " << (type == GL_VERTEX_SHADER ? "vertex" : "fragment") << " shader!" << std::endl;
		std::cout << message << std::endl;
		GLCall(glDeleteShader(id));
		return 0;
	}

	return id;
}

void Shader::link()
{
	GLCall(glLinkProgram(m_programID));
	GLCall(glValidateProgram(m_programID));
}

void Shader::bind()
{
	GLCall(glUseProgram(m_programID));
}

void Shader::unbind()
{
	GLCall(glUseProgram(0));
}

void Shader::cleanUp()
{
	unbind();
	GLCall(glDeleteProgram(m_programID));
}