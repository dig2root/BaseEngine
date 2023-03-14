#pragma once

#include <glad/glad.h>
#include <iostream>

class Shader
{
public:
	Shader() = default;
	Shader(const std::string& filename);
	
	void bind();
	void unbind();
	void cleanUp();

	// Getters and Setters
	std::string getVertexShaderSource() const { return m_vertexShaderSource; }
	std::string getFragmentShaderSource() const { return m_fragmentShaderSource; }

private:
	GLuint m_programID;
	GLuint m_vertexShaderID;
	GLuint m_fragmentShaderID;
	std::string m_vertexShaderSource;
	std::string m_fragmentShaderSource;

	void parseShader(const std::string& filename);
	void createShader();
	GLuint compileShader(GLuint type, const std::string& source);
	void link();
};