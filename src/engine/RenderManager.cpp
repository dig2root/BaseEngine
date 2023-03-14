#include "engine/RenderManager.h"

void RenderManager::init()
{
	// Shader
	m_shader.parseShader("../../../resources/shaders/basic.shader");
	m_shader.createShader();

	// Vertex Array Object
	GLCall(glGenVertexArrays(1, &m_VAO));
	GLCall(glBindVertexArray(m_VAO));

	// Vertex Buffer
	float positions[8] = {
		-0.5f, -0.5f, // 0
		-0.5f, 0.5f,  // 1
		0.5f, 0.5f,   // 2
		0.5f, -0.5f,  // 3
	};

	m_vertexBuffer = VertexBuffer(positions, 8 * sizeof(float));

	GLCall(glEnableVertexAttribArray(0));
	GLCall(glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(float), 0));

	// Index Buffer
	unsigned int indices[] = {
		0, 1, 2,
		2, 3, 0
	};

	m_indexBuffer = IndexBuffer(indices, 6);
}

void RenderManager::render()
{
	GLCall(glClearColor(0.0f, 0.0f, 0.0f, 1.0f));
	
	m_shader.bind();
	GLCall(glBindVertexArray(m_VAO));
	GLCall(glDrawElements(GL_TRIANGLES, m_indexBuffer.getCount(), GL_UNSIGNED_INT, nullptr));
	GLCall(glBindVertexArray(0));
	m_shader.unbind();
}

void RenderManager::cleanUp()
{
	m_shader.cleanUp();
	m_vertexBuffer.cleanUp();
	m_indexBuffer.cleanUp();
	GLCall(glDeleteVertexArrays(1, &m_VAO));
}