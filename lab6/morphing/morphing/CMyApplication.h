#pragma once
#include "CGLapplication.h"
#include "Shader.h"

class CMyApplication : public CGLApplication
{
public:
	CMyApplication(const char* title, int width, int height, int argc, char* argv[]);
	~CMyApplication() = default;

protected:
	virtual void OnDisplay();
	virtual void OnInit();
	virtual void OnReshape(int width, int height);

private:
	void InitShaders();

private:
	CProgram m_program;
	CShader m_vertexShader;
};
