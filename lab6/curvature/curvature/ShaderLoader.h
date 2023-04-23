#pragma once

class ShaderLoader
{
public:
	ShaderLoader() = delete;
	~ShaderLoader() = delete;

	static GLuint LoadShader(GLenum shaderType, const wchar_t* fileName, GLuint shaderId = 0);
};
