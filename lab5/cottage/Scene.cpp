#include "pch.h"
#include "Scene.h"
#include "Cube.h"
#include "CTextureLoader.h"

namespace
{
const std::wstring WOOD_TEXTURE = L"./image.jpg";
}

Scene::Scene()
{
	m_cube.SetSideColor(CubeSide::NEGATIVE_X, { 1, 1, 1, 1 });
	m_cube.SetSideColor(CubeSide::POSITIVE_X, { 1, 1, 1, 1 });
	m_cube.SetSideColor(CubeSide::NEGATIVE_Y, { 1, 1, 1, 1 });
	m_cube.SetSideColor(CubeSide::POSITIVE_Y, { 1, 1, 1, 1 });
	m_cube.SetSideColor(CubeSide::NEGATIVE_Z, { 1, 1, 1, 1 });
	m_cube.SetSideColor(CubeSide::POSITIVE_Z, { 1, 1, 1, 1 });
	m_cube.SetSpecularColor({ 1, 1, 1, 1 });
	m_cube.SetShininess(4.0f);
}

void Scene::Draw() const
{
	if (!m_texture)
	{
		// ��������� �������� ��� ������ ������ ������ Draw()
		CTextureLoader loader;
		m_texture.Attach(loader.LoadTexture2D(WOOD_TEXTURE));
	}

	// ������������ �������� � �������� �������

	glEnable(GL_TEXTURE_2D);
	m_texture.Bind();

	// ��������� ������� ������� (�������������� ������ � �������� modelview)
	// � ������������ �������
	// (������� ������ ��� ��������, � ����� ��������� ���)
	glPushMatrix();
	// ������ �����
	m_cube.Draw();
	// ��������������� ������� �������
	glPopMatrix();
}
