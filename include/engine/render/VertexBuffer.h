#pragma once

#include <glad/glad.h>

class VertexBuffer
{
public:
	VertexBuffer() = default;
	VertexBuffer(const void* data, unsigned int size);
	~VertexBuffer();

	void bind() const;
	void unbind() const;
	void cleanUp() const;

private:
	GLuint m_vboID;
};