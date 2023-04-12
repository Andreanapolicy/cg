#include "pch.h"
#include "Scene.h"
#include "Cube.h"
#include "CTextureLoader.h"
#include "TextureResourceName.h"

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
	DrawLand();

	if (!m_woodTexture)
	{
		CTextureLoader loader;
		m_woodTexture.Attach(loader.LoadTexture2D(texture::name::WOOD_TEXTURE));
	}

	glEnable(GL_TEXTURE_2D);
	m_woodTexture.Bind();

	glPushMatrix();
	glScalef(0.3f, 1.0f, 1.0f);
	m_cube.Draw();
	glPopMatrix();


	glPushMatrix();
	glTranslatef(2.0f, 0.0f, 2.0f);
	m_cube.Draw();

	glPopMatrix();
}

void Scene::DrawLand() const
{
	if (!m_landTexture)
	{
		CTextureLoader loader;
		m_landTexture.Attach(loader.LoadTexture2D(texture::name::LAND_TEXTURE));
	}
	glEnable(GL_TEXTURE_2D);
	m_landTexture.Bind();
	glPushMatrix();

	for (auto indexI = -2.0f; indexI <= 2.0f; indexI += 1.0f)
	{
		for (auto indexJ = -2.0f; indexJ <= 2.0f; indexJ += 1.0f)
		{
			glPushMatrix();
			{
				glScalef(4.0f, 0.1f, 4.0f);
				glTranslatef(indexI, -5.0f, indexJ);
				m_cube.Draw();
			}
			glPopMatrix();
		}
	}
}