#include <cassert>

#include "index_buffer.hpp"


namespace mystery {
	namespace graphics {


		IndexBuffer::IndexBuffer(const unsigned int* indices, unsigned int indicesCount)
			: m_Count(indicesCount)
		{
			assert(sizeof(unsigned int) == sizeof(GLuint));

			glGenBuffers(1, &m_IndexBufferID);

			// here we tell to openGl what kind of buffer this is
			glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_IndexBufferID);

			// here we allocate memory and store data within 
			glBufferData(GL_ELEMENT_ARRAY_BUFFER, indicesCount * sizeof(unsigned int), indices, GL_STATIC_DRAW);
		}

		IndexBuffer::~IndexBuffer()
		{
			glDeleteBuffers(1, &m_IndexBufferID);
		}

		void IndexBuffer::Bind() const
		{
			glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_IndexBufferID);
		}

		void IndexBuffer::Unbind() const
		{
			glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
		}
	
	
	}
}