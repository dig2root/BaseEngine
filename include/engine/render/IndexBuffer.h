#pragma once

#include <glad/glad.h>

class IndexBuffer
{
public:
	IndexBuffer() = default;
	IndexBuffer(const unsigned int* data, unsigned int count);
	~IndexBuffer();

	void bind() const;
	void unbind() const;
	void cleanUp() const;

	GLuint getCount() const { return m_count; }

private:
	GLuint m_iboID;
	GLuint m_count = 0;
};