#version 430 core

layout(location = 0) in vec3 position;
layout(location = 1) in vec2 textureCoord;

// lets transfer some data to the fragment shader
out vec2 v_TexCoord;

// model, view, projection matrix
uniform mat4 u_MVP;

void main()
{
	gl_Position = u_MVP * vec4(position, 1.0f);
	v_TexCoord = textureCoord;
}