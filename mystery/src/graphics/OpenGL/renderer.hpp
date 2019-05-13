#pragma once

#include <GL\glew.h>

// all graphics objects
#include "vertex_array.hpp"
#include "index_buffer.hpp"
#include "shader.hpp"
#include "texture.hpp"
#include "vertex_buffer.hpp"
#include "vertex_buffer_layout.hpp"

namespace mystery {
	namespace graphics {

		class Renderer {
		private:
			unsigned int m_RendererId;
		public:
			Renderer();
			~Renderer();

			void Draw(const VertexArray& va, const IndexBuffer& ib, const Shader& shader);

			void Clear();
			void Blend();
			void WireframeMode();
			void EnableDepthTest();
			void EnableErrorDebug();
		};

	}
}