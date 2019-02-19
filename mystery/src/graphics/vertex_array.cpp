#include "vertex_array.hpp"
#include "vertex_buffer_layout.hpp"
#include "index_buffer.hpp"

namespace mystery {
	namespace graphics {

		VertexArray::VertexArray()
		{
			glGenVertexArrays(1, &m_VertexArrayID);
		}

		VertexArray::~VertexArray()
		{
			glDeleteVertexArrays(1, &m_VertexArrayID);
		}

		void VertexArray::AddBuffer(const VertexBuffer &vertex_buffer, const VertexBufferLayout &layout)
		{
			Bind();
			vertex_buffer.Bind();

			const std::vector<VertexBufferElement> elements = layout.GetElements();

			for (unsigned int i = 0; i < elements.size(); i++) {

				const auto& element = elements[i];
				unsigned int offset = 0;

				glEnableVertexAttribArray(i);
				glVertexAttribPointer(i, element.count, element.type, element.normalized, layout.GetStride(), (const void*)offset);

				offset += element.count * VertexBufferElement::GetSizeOfType(element.type);

			}

		}

		void VertexArray::Bind() const
		{
			glBindVertexArray(m_VertexArrayID);
		}

		void VertexArray::Unbind() const
		{
			glBindVertexArray(0);
		}

	}
}