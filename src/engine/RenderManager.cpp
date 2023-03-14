#include "engine/RenderManager.h"

void RenderManager::init()
{
	// Shader
	m_shaderPtr = new Shader("../../../resources/shaders/basic.shader");

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

	m_vertexBufferPtr = new VertexBuffer(positions, 8 * sizeof(float));

	GLCall(glEnableVertexAttribArray(0));
	GLCall(glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(float), 0));

	// Index Buffer
	unsigned int indices[] = {
		0, 1, 2,
		2, 3, 0
	};

	m_indexBufferPtr = new IndexBuffer(indices, 6);
}

void RenderManager::render()
{
	GLCall(glClear(GL_COLOR_BUFFER_BIT));

	m_shaderPtr->bind();
	GLCall(glBindVertexArray(m_VAO));
	GLCall(glDrawElements(GL_TRIANGLES, m_indexBufferPtr->getCount(), GL_UNSIGNED_INT, nullptr));
	GLCall(glBindVertexArray(0));
	m_shaderPtr->unbind();
}

void RenderManager::cleanUp()
{
	m_shaderPtr->cleanUp();
	m_vertexBufferPtr->cleanUp();
	m_indexBufferPtr->cleanUp();
	GLCall(glDeleteVertexArrays(1, &m_VAO));
}