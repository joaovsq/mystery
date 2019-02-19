#pragma once

#include <iostream>
#include <unordered_map>

#include <GL/glew.h>
#include <glm/glm.hpp>

namespace mystery {
	namespace graphics {

		class Shader {

		private:
			unsigned int m_ShaderId;

			// to avoid repetitions in the getUniformLocation function
			std::unordered_map<std::string, int> m_LocationCache;
		public:
			Shader(const std::string vert_shader_path, const std::string frag_shader_path);
			~Shader();

			void Bind() const;
			void Unbind() const;

			void SetUniform4f(const std::string& name, float v0, float v1, float v2, float v3);
			void SetUniform1i(const std::string& name, int v0);
			void SetUniformMat4(const std::string& name, const glm::mat4& matrix);


		private:

			std::string ParseShaderFile(const std::string& filepath);

			unsigned int CompileShader(unsigned int shader_type, const std::string& shader_src_code);
			unsigned int CreateShader(const std::string& src_vertex_shader, const std::string& src_fragment_shader);

			int GetUniformLocation(const std::string& name);
		};

	}
}