#pragma once

#include "vertex_buffer.hpp"

namespace mystery {
	namespace graphics {

		class VertexBufferLayout;

		class VertexArray {
		private:
			unsigned int m_VertexArrayID;
		public:
			VertexArray();
			~VertexArray();

			void AddBuffer(const VertexBuffer& vertex_buffer, const VertexBufferLayout& layout);

			void Bind() const;
			void Unbind() const;
		};

	}
}