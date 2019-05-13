#pragma once

#include<GL/glew.h>

namespace mystery {
	namespace graphics {

		class VertexBuffer {
		private:
			unsigned int m_VertexBufferID;
		public:
			VertexBuffer(const void* data, unsigned int size);
			~VertexBuffer();

			void Bind() const;
			void Unbind() const;
		};

	}
}