#include "shader.hpp"

#include <fstream>
#include <string>
#include <sstream>

namespace mystery {
	namespace graphics {

		// Reads a shader file and returns it in string format
		std::string Shader::ParseShaderFile(const std::string& filepath) {

			std::ifstream file_stream(filepath);

			std::string line;
			std::stringstream string_stream;

			while (getline(file_stream, line)) {
				string_stream << line << '\n';
			}

			return string_stream.str();
		}


		Shader::Shader(const std::string vert_shader_path, const std::string frag_shader_path)
			: m_ShaderId(0)
		{
			const auto src_vertex_shader = ParseShaderFile(vert_shader_path);
			const auto src_fragment_shader = ParseShaderFile(frag_shader_path);

			m_ShaderId = CreateShader(src_vertex_shader, src_fragment_shader);
		}

		Shader::~Shader()
		{
			glDeleteProgram(m_ShaderId);
		}

		void Shader::Bind() const
		{
			glUseProgram(m_ShaderId);
		}

		void Shader::Unbind() const
		{
			glUseProgram(0);
		}

		// gets the uniform location and returns it
		int Shader::GetUniformLocation(const std::string& name)
		{
			// if this location is in the cache, then just return it
			// otherwise get the uniform location and store it in the cache
			if (m_LocationCache.find(name) != m_LocationCache.end()) {
				return m_LocationCache[name];
			}
			else {
				int location = glGetUniformLocation(m_ShaderId, name.c_str());

				if (location == -1)
					std::cout << "WARNING: uniform" << name << "doesn't exist! " << std::endl;

				m_LocationCache[name] = location;
				return location;
			}

		}

		void Shader::SetUniform1i(const std::string& name, int v0)
		{
			glUniform1i(GetUniformLocation(name), v0);
		}

		void Shader::SetUniform4f(const std::string& name, float v0, float v1, float v2, float v3)
		{
			glUniform4f(GetUniformLocation(name), v0, v1, v2, v3);
		}

		// Sets a matrix unfirom
		void Shader::SetUniformMat4(const std::string& name, const glm::mat4& matrix)
		{
			glUniformMatrix4fv(GetUniformLocation(name), 1, GL_FALSE, &matrix[0][0]);
		}

		// compiles a shader source code using the provided type
		unsigned int Shader::CompileShader(unsigned int shader_type, const std::string& shader_src_code) {

			unsigned int shader_id = glCreateShader(shader_type);
			const char* src_char = shader_src_code.c_str();
			glShaderSource(shader_id, 1, &src_char, nullptr);
			glCompileShader(shader_id);

			// error handling
			int result;
			glGetShaderiv(shader_id, GL_COMPILE_STATUS, &result);

			// if something went wrong
			if (result == GL_FALSE) {

				// message length
				int length;
				glGetShaderiv(shader_id, GL_INFO_LOG_LENGTH, &length);

				// here we are allocating a array of chars in the stack (yes, this is kinda hacky)
				char* message = (char*)alloca(length * sizeof(char));
				glGetShaderInfoLog(shader_id, length, &length, message);

				std::cout << "SHADER: Failed to compile: " << std::endl;
				std::cout << (shader_type == GL_VERTEX_SHADER ? "vertex shader" : "fragment shader") << std::endl;
				std::cout << message << std::endl;

				glDeleteShader(shader_id);

				return 0;
			}

			return shader_id;
		}

		// generates a program for the vertex and fragment shaders provided
		unsigned int Shader::CreateShader(const std::string& src_vertex_shader, const std::string& src_fragment_shader) {

			unsigned int program = glCreateProgram();
			unsigned int vertex_shader = CompileShader(GL_VERTEX_SHADER, src_vertex_shader);
			unsigned int fragment_shader = CompileShader(GL_FRAGMENT_SHADER, src_fragment_shader);

			glAttachShader(program, vertex_shader);
			glAttachShader(program, fragment_shader);
			glLinkProgram(program);
			glValidateProgram(program);

			glDeleteShader(vertex_shader);
			glDeleteShader(fragment_shader);

			return program;
		}

	}
}