#include "pch.h"
#include "Scene.h"
#include "CTextureLoader.h"
#include "Cube.h"
#include "TextureResourceName.h"

void Scene::Draw() const
{
	DrawLand();
	DrawHouseMainPart();
	DrawHouseAdditionalPart();
}

std::shared_ptr<Cube> Scene::CreateCube(float size) const
{
	auto cube = std::make_shared<Cube>(size);

	cube->SetSideColor(CubeSide::NEGATIVE_X, { 1, 1, 1, 1 });
	cube->SetSideColor(CubeSide::POSITIVE_X, { 1, 1, 1, 1 });
	cube->SetSideColor(CubeSide::NEGATIVE_Y, { 1, 1, 1, 1 });
	cube->SetSideColor(CubeSide::POSITIVE_Y, { 1, 1, 1, 1 });
	cube->SetSideColor(CubeSide::NEGATIVE_Z, { 1, 1, 1, 1 });
	cube->SetSideColor(CubeSide::POSITIVE_Z, { 1, 1, 1, 1 });
	cube->SetSpecularColor({ 1, 1, 1, 1 });
	cube->SetShininess(4.0f);

	return cube;
}

void Scene::DrawLand() const
{
	auto floor = CreateCube(1);

	if (!m_landTexture)
	{
		CTextureLoader loader;
		m_landTexture.Attach(loader.LoadTexture2D(texture::name::LAND_TEXTURE));
	}
	glEnable(GL_TEXTURE_2D);
	m_landTexture.Bind();

	for (auto indexI = -2.0f; indexI <= 2.0f; indexI += 1.0f)
	{
		for (auto indexJ = -2.0f; indexJ <= 2.0f; indexJ += 1.0f)
		{
			glPushMatrix();
			{
				glScalef(4.0f, 0.1f, 4.0f);
				glTranslatef(indexI, -5.0f, indexJ);
				floor->Draw();
			}
			glPopMatrix();
		}
	}
}

void Scene::DrawHouseMainPart() const
{
	auto cube = CreateCube(3);
	if (!m_woodTexture)
	{
		CTextureLoader loader;
		loader.SetWrapMode(GL_REPEAT, GL_REPEAT);
		m_woodTexture.Attach(loader.LoadTexture2D(texture::name::WOOD_TEXTURE));
	}
	glEnable(GL_TEXTURE_2D);
	m_woodTexture.Bind();

	glPushMatrix();
	{
		glScalef(1.0f, 1.0f, 0.7f);
		glTranslatef(1.0f, 1.0f, 1.0f);
		cube->Draw();
	}
	glPopMatrix();
	glPushMatrix();
	{
		glScalef(1.0f, 1.0f, 0.7f);
		glTranslatef(-2.0f, 1.0f, 1.0f);
		cube->Draw();
	}
	glPopMatrix();
}

void Scene::DrawHouseAdditionalPart() const
{
	auto cube = CreateCube(2);
	if (!m_woodTexture)
	{
		CTextureLoader loader;
		loader.SetWrapMode(GL_REPEAT, GL_REPEAT);
		m_woodTexture.Attach(loader.LoadTexture2D(texture::name::WOOD_TEXTURE));
	}
	glEnable(GL_TEXTURE_2D);
	m_woodTexture.Bind();

	glPushMatrix();
	{
		glScalef(1.5f, 1.3f, 0.7f);
		glTranslatef(2.0f, 0.0f, 1.0f);
		cube->Draw();
	}
	glPopMatrix();
}