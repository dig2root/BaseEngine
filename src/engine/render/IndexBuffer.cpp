#include "engine/render/IndexBuffer.h"
#include "engine/GLErrorManager.h"

#include <iostream>

IndexBuffer::IndexBuffer(const unsigned int* data, unsigned int count) : m_count(count)
{
	GLCall(glGenBuffers(1, &m_iboID));
	GLCall(glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_iboID));
	GLCall(glBufferData(GL_ELEMENT_ARRAY_BUFFER, count * sizeof(unsigned int), data, GL_STATIC_DRAW));
	std::cout << "IndexBuffer created" << std::endl;
}

IndexBuffer::~IndexBuffer()
{
	GLCall(glDeleteBuffers(1, &m_iboID));
}

void IndexBuffer::bind() const
{
	GLCall(glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_iboID));
}

void IndexBuffer::unbind() const
{
	GLCall(glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0));
}

void IndexBuffer::cleanUp() const
{
	GLCall(glDeleteBuffers(1, &m_iboID));
}