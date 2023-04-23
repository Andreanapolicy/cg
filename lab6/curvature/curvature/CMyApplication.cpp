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
	// Проверяем поддержку геометрических шейдеров видеокартой
	if (!GLEW_EXT_geometry_shader4)
	{
		throw std::runtime_error("The OpenGL implementation does not support geometry shaders");
	}

	ShaderLoader loader;
	// Загружаем шейдеры
	m_vertexShader = loader.LoadShader(GL_VERTEX_SHADER, L"shaders\\vertex_shader.vsh");

	// Создаем программный объект и присоединяем шейдеры к нему
	m_program.Create();
	m_program.AttachShader(m_vertexShader);

	// Компилируем шейдеры
	ShaderCompiler compiler;
	compiler.CompileShader(m_vertexShader);
	compiler.CheckStatus();

	// Задаем параметры шейдерной программы
	// тип входных примитивов: точки
	m_program.SetParameter(GL_GEOMETRY_INPUT_TYPE_ARB, GL_POINTS);
	// типв выходных примитивов: лента из треугольникков
	m_program.SetParameter(GL_GEOMETRY_OUTPUT_TYPE_ARB, GL_TRIANGLE_STRIP);
	// Максимальное количество вершин, порождаемых геометрическим шейдером
	// за один вызов. Для ленты из двух треугольников оно равно 4
	m_program.SetParameter(GL_GEOMETRY_VERTICES_OUT_EXT, 4);

	// Компонуем программу и проверяем ее статус
	ProgramLinker linker;
	linker.LinkProgram(m_program);
	linker.CheckStatus();

	// Получаем расположение uniform-переменных, используемых в
	// шейдерной программе
	m_sizeLocation = m_program.GetUniformLocation("Size");
	m_textureMapLocation = m_program.GetUniformLocation("TextureMap");
}

void CMyApplication::OnDisplay()
{
	glClearColor(0.6f, 0.6f, 0.6f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT);

	// Активируем шейдерную программу и задаем значения ее uniform-переменных
	glUseProgram(m_program);
	if (m_sizeLocation >= 0)
	{
		// размеры точки в нормализованных координатах
		glUniform2f(m_sizeLocation, 0.6f, 0.6f);
	}
	if (m_textureMapLocation >= 0)
	{
		// задаем номер текстурного модуля 0 для использования дискретизатором
		// TextureMap
		glUniform1i(m_textureMapLocation, 0);
	}

	glPushMatrix();
	glScalef(0.3f, 0.2f, 0.3f);

	Scene::Draw();
	glPopMatrix();


	// Переключаемся на стандартный конвейер
	glUseProgram(0);
}

void CMyApplication::OnReshape(int width, int height)
{
	glViewport(0, 0, width, height);
}