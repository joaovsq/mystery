#include "vertex_buffer.hpp"

namespace mystery {
	namespace graphics {

		VertexBuffer::VertexBuffer(const void* data, unsigned int bufferSize)
		{
			glGenBuffers(1, &m_VertexBufferID);

			glBindBuffer(GL_ARRAY_BUFFER, m_VertexBufferID);

			// here we allocate memory and store data within 
			glBufferData(GL_ARRAY_BUFFER, bufferSize, data, GL_STATIC_DRAW);
		}

		VertexBuffer::~VertexBuffer()
		{
			glDeleteBuffers(1, &m_VertexBufferID);
		}

		void VertexBuffer::Bind() const
		{
			glBindBuffer(GL_ARRAY_BUFFER, m_VertexBufferID);
		}

		void VertexBuffer::Unbind() const
		{
			glBindBuffer(GL_ARRAY_BUFFER, 0);
		}

	}
}