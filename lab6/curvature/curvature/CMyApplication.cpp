#include "pch.h"
#include "CMyApplication.h"
#include "ProgramLinker.h"
#include "ShaderCompiler.h"
#include "ShaderLoader.h"
#include "Scene.h"

CMyApplication::CMyApplication(const char* title, int width, int height, int argc, char* argv[])
	: CGLApplication(title, argc, argv, width, height)
{
}

CMyApplication::~CMyApplication(void)
{
}

void CMyApplication::OnInit()
{
	InitShaders();
}

void CMyApplication::InitShaders()
{
	// ��������� ��������� �������������� �������� �����������
	if (!GLEW_EXT_geometry_shader4)
	{
		throw std::runtime_error("The OpenGL implementation does not support geometry shaders");
	}

	ShaderLoader loader;
	// ��������� �������
	m_vertexShader = loader.LoadShader(GL_VERTEX_SHADER, L"shaders\\vertex_shader.vsh");

	// ������� ����������� ������ � ������������ ������� � ����
	m_program.Create();
	m_program.AttachShader(m_vertexShader);

	// ����������� �������
	ShaderCompiler compiler;
	compiler.CompileShader(m_vertexShader);
	compiler.CheckStatus();

	// ������ ��������� ��������� ���������
	// ��� ������� ����������: �����
	m_program.SetParameter(GL_GEOMETRY_INPUT_TYPE_ARB, GL_POINTS);
	// ���� �������� ����������: ����� �� ��������������
	m_program.SetParameter(GL_GEOMETRY_OUTPUT_TYPE_ARB, GL_TRIANGLE_STRIP);
	// ������������ ���������� ������, ����������� �������������� ��������
	// �� ���� �����. ��� ����� �� ���� ������������� ��� ����� 4
	m_program.SetParameter(GL_GEOMETRY_VERTICES_OUT_EXT, 4);

	// ��������� ��������� � ��������� �� ������
	ProgramLinker linker;
	linker.LinkProgram(m_program);
	linker.CheckStatus();

	// �������� ������������ uniform-����������, ������������ �
	// ��������� ���������
	m_sizeLocation = m_program.GetUniformLocation("Size");
	m_textureMapLocation = m_program.GetUniformLocation("TextureMap");
}

void CMyApplication::OnDisplay()
{
	glClearColor(0.6f, 0.6f, 0.6f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT);

	// ���������� ��������� ��������� � ������ �������� �� uniform-����������
	glUseProgram(m_program);
	if (m_sizeLocation >= 0)
	{
		// ������� ����� � ��������������� �����������
		glUniform2f(m_sizeLocation, 0.6f, 0.6f);
	}
	if (m_textureMapLocation >= 0)
	{
		// ������ ����� ����������� ������ 0 ��� ������������� ���������������
		// TextureMap
		glUniform1i(m_textureMapLocation, 0);
	}

	glPushMatrix();
	glScalef(0.3f, 0.2f, 0.3f);

	Scene::Draw();
	glPopMatrix();


	// ������������� �� ����������� ��������
	glUseProgram(0);
}

void CMyApplication::OnReshape(int width, int height)
{
	glViewport(0, 0, width, height);
}