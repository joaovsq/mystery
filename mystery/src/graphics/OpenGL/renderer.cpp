#include "renderer.hpp"

// simple opengl error call back
void GLAPIENTRY openglErrorCallback(GLenum source,
	GLenum type,
	GLuint id,
	GLenum severity,
	GLsizei length,
	const GLchar* message,
	const void* userParam)
{
	std::cout << (stderr, "GL CALLBACK: %s type = 0x%x, severity = 0x%x, message = %s\n",
		(type == GL_DEBUG_TYPE_ERROR ? "** GL ERROR **" : ""),
		type, severity, message) << std::endl;
}

namespace mystery {
	namespace graphics {

		// in the Renderer constructor we just initialize the glew library.
		Renderer::Renderer() {

			// IMPORTANT NOTE: This must be done inside a valid OpenGL Context !!!!
			if (glewInit() != GLEW_OK) {
				std::cout << "An error ocurred when starting glew" << std::endl;
			}
			std::cout << "OpenGL version: " << glGetString(GL_VERSION) << std::endl;

		}

		Renderer::~Renderer() {

		}

		void Renderer::Draw(const VertexArray& va, const IndexBuffer& ib, const Shader& shader)
		{
			shader.Bind();
			va.Bind();
			ib.Bind();

			glDrawElements(GL_TRIANGLES, ib.GetCount(), GL_UNSIGNED_INT, 0);
		}

		void Renderer::Clear()
		{
			// TODO: change this background color.
			glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
			glClear(GL_COLOR_BUFFER_BIT);
			//	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		}

		void Renderer::Blend()
		{
			// texture blending
			glEnable(GL_BLEND);
			glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
		}

		// change the renderer to a wireframe mode view
		void Renderer::WireframeMode() {
			glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
		}

		void Renderer::EnableDepthTest() {
			glEnable(GL_DEPTH_TEST);
		}

		void Renderer::EnableErrorDebug() {

			// Enables opengl debug output
			glEnable(GL_DEBUG_OUTPUT);
			glDebugMessageCallback(openglErrorCallback, 0);
		}

	}
}