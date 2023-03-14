#include <glad/glad.h>

#include "GLErrorManager.h"
#include "render/Shader.h"
#include "render/VertexBuffer.h"
#include "render/IndexBuffer.h"

class RenderManager
{
public:
	void init();
	void render();
	void cleanUp();

private:
	Shader* m_shaderPtr;
	VertexBuffer* m_vertexBufferPtr;
	IndexBuffer* m_indexBufferPtr;
	GLuint m_VAO;
};