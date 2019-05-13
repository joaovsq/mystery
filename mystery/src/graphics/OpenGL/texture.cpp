#include "texture.hpp"

#include <stb_image/stb_image.h>

namespace mystery {
	namespace graphics {

		Texture::Texture(const std::string &path)
			: m_TextureID(0), m_FilePath(path), m_LocalBuffer(nullptr),
			m_Width(0), m_Height(0), m_BPP(0)
		{
			glGenTextures(1, &m_TextureID);
			glBindTexture(GL_TEXTURE_2D, m_TextureID);

			// opengl expects that the image starts in the bottom left
			// so we need to flip it  
			stbi_set_flip_vertically_on_load(1);

			// loads the texture data from a given path
			m_LocalBuffer = stbi_load(path.c_str(), &m_Width, &m_Height, &m_BPP, 4);

			// OpenGL texture parameters
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

			glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, (float)m_Width, (float)m_Height, 0, GL_RGBA, GL_UNSIGNED_BYTE, m_LocalBuffer);
			glGenerateMipmap(GL_TEXTURE_2D);

			// mipmap
			//glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
			//glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

			//unbind texture 
			glBindTexture(GL_TEXTURE_2D, 0);

			// if there is data,
			// free all the pixel data
			if (m_LocalBuffer)
				stbi_image_free(m_LocalBuffer);
		}


		Texture::~Texture()
		{
			glDeleteTextures(1, &m_TextureID);
		}

		void Texture::Bind(unsigned int slot) const
		{
			glActiveTexture(GL_TEXTURE0 + slot);
			glBindTexture(GL_TEXTURE_2D, m_TextureID);
		}

		void Texture::Unbind()
		{
			glBindTexture(GL_TEXTURE_2D, 0);
		}

	}
}