#include "pch.h"
#include "Cube.h"

Cube::Cube(float size)
	: m_size(size)
{
	constexpr glm::vec4 defaultColor{ 1, 1, 1, 1 };
	SetSideColor(CubeSide::NEGATIVE_X, defaultColor);
	SetSideColor(CubeSide::POSITIVE_X, defaultColor);
	SetSideColor(CubeSide::NEGATIVE_Y, defaultColor);
	SetSideColor(CubeSide::POSITIVE_Y, defaultColor);
	SetSideColor(CubeSide::NEGATIVE_Z, defaultColor);
	SetSideColor(CubeSide::POSITIVE_Z, defaultColor);
}

void Cube::Draw() const
{
	glEnable(GL_COLOR_MATERIAL);
	// ÷вет вершины будет управл€ть диффузным и фоновым цветом материала
	glColorMaterial(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE);
	glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, glm::value_ptr(m_specularColor));
	glMaterialf(GL_FRONT_AND_BACK, GL_SHININESS, m_shininess);

	glBegin(GL_QUADS);
	{
		glNormal3f(0.0f, 0.0f, 1.0f);
		glTexCoord2f(0.0f, 0.0f);
		glVertex3f(-0.5f * m_size, -0.5f * m_size, 0.5f * m_size);
		glTexCoord2f(1.0f, 0.0f);
		glVertex3f(0.5f * m_size, -0.5f * m_size, 0.5f * m_size);
		glTexCoord2f(1.0f, 1.0f);
		glVertex3f(0.5f * m_size, 0.5f * m_size, 0.5f * m_size);
		glTexCoord2f(0.0f, 1.0f);
		glVertex3f(-0.5f * m_size, 0.5f * m_size, 0.5f * m_size);

		glNormal3f(0.0f, 0.0f, -1.0f);
		glTexCoord2f(0.0f, 0.0f);
		glVertex3f(0.5f * m_size, -0.5f * m_size, -0.5f * m_size);
		glTexCoord2f(1.0f, 0.0f);
		glVertex3f(-0.5f * m_size, -0.5f * m_size, -0.5f * m_size);
		glTexCoord2f(1.0f, 1.0f);
		glVertex3f(-0.5f * m_size, 0.5f * m_size, -0.5f * m_size);
		glTexCoord2f(0.0f, 1.0f);
		glVertex3f(0.5f * m_size, 0.5f * m_size, -0.5f * m_size);

		glNormal3f(1.0f, 0.0f, 0.0f);
		glTexCoord2f(0.0f, 0.0f);
		glVertex3f(0.5f * m_size, -0.5f * m_size, 0.5f * m_size);
		glTexCoord2f(1.0f, 0.0f);
		glVertex3f(0.5f * m_size, -0.5f * m_size, -0.5f * m_size);
		glTexCoord2f(1.0f, 1.0f);
		glVertex3f(0.5f * m_size, 0.5f * m_size, -0.5f * m_size);
		glTexCoord2f(0.0f, 1.0f);
		glVertex3f(0.5f * m_size, 0.5f * m_size, 0.5f * m_size);

		glNormal3f(-1.0f, 0.0f, 0.0f);
		glTexCoord2f(0.0f, 0.0f);
		glVertex3f(-0.5f * m_size, -0.5f * m_size, -0.5f * m_size);
		glTexCoord2f(1.0f, 0.0f);
		glVertex3f(-0.5f * m_size, -0.5f * m_size, 0.5f * m_size);
		glTexCoord2f(1.0f, 1.0f);
		glVertex3f(-0.5f * m_size, 0.5f * m_size, 0.5f * m_size);
		glTexCoord2f(0.0f, 1.0f);
		glVertex3f(-0.5f * m_size, 0.5f * m_size, -0.5f * m_size);

		glNormal3f(0.0f, 1.0f, 0.0f);
		glTexCoord2f(0.0f, 0.0f);
		glVertex3f(-0.5f * m_size, 0.5f * m_size, 0.5f * m_size);
		glTexCoord2f(1.0f, 0.0f);
		glVertex3f(0.5f * m_size, 0.5f * m_size, 0.5f * m_size);
		glTexCoord2f(1.0f, 1.0f);
		glVertex3f(0.5f * m_size, 0.5f * m_size, -0.5f * m_size);
		glTexCoord2f(0.0f, 1.0f);
		glVertex3f(-0.5f * m_size, 0.5f * m_size, -0.5f * m_size);

		glNormal3f(0.0f, -1.0f, 0.0f);
		glTexCoord2f(0.0f, 0.0f);
		glVertex3f(-0.5f * m_size, -0.5f * m_size, -0.5f * m_size);
		glTexCoord2f(1.0f, 0.0f);
		glVertex3f(0.5f * m_size, -0.5f * m_size, -0.5f * m_size);
		glTexCoord2f(1.0f, 1.0f);
		glVertex3f(0.5f * m_size, -0.5f * m_size, 0.5f * m_size);
		glTexCoord2f(0.0f, 1.0f);
		glVertex3f(-0.5f * m_size, -0.5f * m_size, 0.5f * m_size);
	}
	glEnd();
}

void Cube::SetSideColor(CubeSide side, const glm::vec4& color)
{
	unsigned index = static_cast<unsigned>(side);
	m_sideColors[index] = color;
}

void Cube::SetSpecularColor(glm::vec4 color)
{
	m_specularColor = color;
}

void Cube::SetShininess(float shininess)
{
	m_shininess = shininess;
}
