#pragma once

#include<GL/glew.h>

namespace mystery {
	namespace graphics {

		class IndexBuffer {
		private:
			unsigned int m_IndexBufferID;
			// how many indexes
			unsigned int m_Count;
		public:
			IndexBuffer(const unsigned int* data, unsigned int count);
			~IndexBuffer();

			void Bind() const;
			void Unbind() const;

			inline unsigned int GetCount() const { return m_Count; }
		};


	}
}