#include "engine/render/VertexBuffer.h"
#include "engine/GLErrorManager.h"

#include <iostream>

VertexBuffer::VertexBuffer(const void* data, unsigned int size)
{
	GLCall(glGenBuffers(1, &m_vboID));
	GLCall(glBindBuffer(GL_ARRAY_BUFFER, m_vboID));
	GLCall(glBufferData(GL_ARRAY_BUFFER, size, data, GL_STATIC_DRAW));
	std::cout << "VertexBuffer created : " << m_vboID << std::endl;
}

VertexBuffer::~VertexBuffer()
{
	cleanUp();
	std::cout << "VertexBuffer destroyed : " << m_vboID << std::endl;
}

void VertexBuffer::bind() const
{
	GLCall(glBindBuffer(GL_ARRAY_BUFFER, m_vboID));
}

void VertexBuffer::unbind() const
{
	GLCall(glBindBuffer(GL_ARRAY_BUFFER, 0));
}

void VertexBuffer::cleanUp() const
{
	GLCall(glDeleteBuffers(1, &m_vboID));
}