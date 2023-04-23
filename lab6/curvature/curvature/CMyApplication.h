#pragma once
#include "Shader.h"
#include "CGLapplication.h"

class CMyApplication : public CGLApplication
{
public:
	CMyApplication(const char* title, int width, int height, int argc, char* argv[]);
	~CMyApplication(void);

protected:
	virtual void OnDisplay();
	virtual void OnInit();
	virtual void OnReshape(int width, int height);

private:
	void InitShaders();

private:
	// Шейдерные объекты
	CProgram m_program;
	CShader m_vertexShader;
	// Расположение переменной Size в программном объекте
	GLint m_sizeLocation = 0;
	// Расположение переменной TextureMap в программном объекте
	GLint m_textureMapLocation = 0;
};
