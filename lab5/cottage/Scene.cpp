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
	DrawWindows();
	DrawBalcony();
	DrawDoor();
	DrawGarade();
	DrawRoof();
}

std::shared_ptr<Cube> Scene::CreateCube(float size) const
{
	auto cube = std::make_shared<Cube>(size);
	cube->SetSpecularColor({ 1, 1, 1, 1 });
	cube->SetShininess(4.0f);

	return cube;
}

std::shared_ptr<Pyramid> Scene::CreatePyramid(Pyramid::PyramidSideSize&& size, float height) const
{
	auto pyramid = std::make_shared<Pyramid>(std::move(size), height);
	pyramid->SetSpecularColor({ 1, 1, 1, 1 });
	pyramid->SetShininess(4.0f);

	return pyramid;
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

void Scene::DrawWindows() const
{
	auto cube = CreateCube(0.8);
	if (!m_glassTexture)
	{
		CTextureLoader loader;
		loader.SetWrapMode(GL_REPEAT, GL_REPEAT);
		m_glassTexture.Attach(loader.LoadTexture2D(texture::name::GLASS_TEXTURE));
	}
	glEnable(GL_TEXTURE_2D);
	m_glassTexture.Bind();

	glPushMatrix();
	{
		glTranslatef(1.8f, 1.8f, 1.8f);
		glScalef(1.0f, 1.0f, 0.2f);
		cube->Draw();
	}
	glPopMatrix();

	glPushMatrix();
	{
		glTranslatef(-2.7f, 1.8f, 1.8f);
		glScalef(1.0f, 1.0f, 0.2f);
		cube->Draw();
	}
	glPopMatrix();

	cube = CreateCube(1.5);
	glPushMatrix();
	{
		glTranslatef(-0.4f, 1.7f, 1.8f);
		glScalef(0.85f, 0.6f, 0.2f);
		cube->Draw();
	}
	glPopMatrix();
}

void Scene::DrawBalcony() const
{
	auto cube = CreateCube(0.8);
	if (!m_stoneTexture)
	{
		CTextureLoader loader;
		loader.SetWrapMode(GL_REPEAT, GL_REPEAT);
		m_stoneTexture.Attach(loader.LoadTexture2D(texture::name::STONES_TEXTURE));
	}
	glEnable(GL_TEXTURE_2D);
	m_stoneTexture.Bind();

	glPushMatrix();
	{
		glTranslatef(-0.8f, 1.5f, 2.58f);
		glScalef(1.0f, 0.5f, 0.2f);
		cube->Draw();
	}
	glPopMatrix();
	glPushMatrix();
	{
		glTranslatef(0.0f, 1.5f, 2.58f);
		glScalef(1.0f, 0.5f, 0.2f);
		cube->Draw();
	}
	glPopMatrix();

	glPushMatrix();
	{
		glTranslatef(0.32f, 1.5f, 2.1f);
		glRotatef(90.0f, 0.0f, 1.0f, 0.0f);
		glScalef(1.0f, 0.5f, 0.2f);
		cube->Draw();
	}
	glPopMatrix();

	glPushMatrix();
	{
		glTranslatef(-1.12f, 1.5f, 2.1f);
		glRotatef(90.0f, 0.0f, 1.0f, 0.0f);
		glScalef(1.0f, 0.5f, 0.2f);
		cube->Draw();
	}
	glPopMatrix();

	cube = CreateCube(1.6);
	glPushMatrix();
	{
		glTranslatef(-0.4f, 1.22f, 2.1f);
		glScalef(1.0f, 0.1f, 0.7f);
		cube->Draw();
	}
	glPopMatrix();
}

void Scene::DrawDoor() const
{
	auto cube = CreateCube(1.0);
	if (!m_doorTexture)
	{
		CTextureLoader loader;
		loader.SetWrapMode(GL_REPEAT, GL_REPEAT);
		m_doorTexture.Attach(loader.LoadTexture2D(texture::name::DOOR_TEXTURE));
	}
	glEnable(GL_TEXTURE_2D);
	m_doorTexture.Bind();

	glPushMatrix();
	{
		glTranslatef(-0.4f, 0.0f, 1.75f);
		glScalef(0.6f, 1.1f, 0.05f);
		cube->Draw();
	}
	glPopMatrix();
}

void Scene::DrawGarade() const
{
	auto cube = CreateCube(1.8);

	InitSteelTextureIfNeeded();

	glEnable(GL_TEXTURE_2D);
	m_steelTexture.Bind();

	glPushMatrix();
	{
		glTranslatef(3.5f, 0.0f, 1.45f);
		glScalef(1.0f, 1.0f, 0.05f);
		cube->Draw();
	}
	glPopMatrix();
}

void Scene::DrawRoof() const
{
	auto pyramid = CreatePyramid({ 1.0f, 2.0f, 3.0f, 4.0f }, 0.7);
	InitWoodTextureIfNeeded();
	glEnable(GL_TEXTURE_2D);
	m_woodTexture.Bind();

	glPushMatrix();
	{
		glTranslatef(-2.5f, 1.5f, 0.7f);
		glScalef(2.0f, 2.0f, 2.5f);
		pyramid->Draw();
	}
	glPopMatrix();

	glPushMatrix();
	{
		glTranslatef(-0.5f, 1.5f, 0.7f);
		glScalef(2.0f, 2.0f, 2.5f);
		pyramid->Draw();
	}
	glPopMatrix();

	glPushMatrix();
	{
		glTranslatef(1.5f, 1.5f, 0.7f);
		glScalef(2.0f, 2.0f, 2.5f);
		pyramid->Draw();
	}
	glPopMatrix();

	glPushMatrix();
	{
		glTranslatef(3.5f, 0.3f, 0.7f);
		glScalef(2.2f, 2.0f, 2.0f);
		pyramid->Draw();
	}
	glPopMatrix();
}

void Scene::InitWoodTextureIfNeeded() const
{
	if (!m_woodTexture)
	{
		CTextureLoader loader;
		loader.SetWrapMode(GL_REPEAT, GL_REPEAT);
		m_woodTexture.Attach(loader.LoadTexture2D(texture::name::WOOD_TEXTURE));
	}
}

void Scene::InitSteelTextureIfNeeded() const
{
	if (!m_steelTexture)
	{
		CTextureLoader loader;
		loader.SetWrapMode(GL_REPEAT, GL_REPEAT);
		m_steelTexture.Attach(loader.LoadTexture2D(texture::name::STEEL_TEXTURE));
	}
}

void Scene::InitDoorTextureIfNeeded() const
{
	if (!m_doorTexture)
	{
		CTextureLoader loader;
		loader.SetWrapMode(GL_REPEAT, GL_REPEAT);
		m_doorTexture.Attach(loader.LoadTexture2D(texture::name::DOOR_TEXTURE));
	}
}

void Scene::InitStoneTextureIfNeeded() const
{
	if (!m_stoneTexture)
	{
		CTextureLoader loader;
		loader.SetWrapMode(GL_REPEAT, GL_REPEAT);
		m_stoneTexture.Attach(loader.LoadTexture2D(texture::name::STONES_TEXTURE));
	}
}

void Scene::InitLandTextureIfNeeded() const
{
	if (!m_landTexture)
	{
		CTextureLoader loader;
		loader.SetWrapMode(GL_REPEAT, GL_REPEAT);
		m_landTexture.Attach(loader.LoadTexture2D(texture::name::LAND_TEXTURE));
	}
}

void Scene::InitGlassTextureIfNeeded() const
{
	if (!m_glassTexture)
	{
		CTextureLoader loader;
		loader.SetWrapMode(GL_REPEAT, GL_REPEAT);
		m_glassTexture.Attach(loader.LoadTexture2D(texture::name::GLASS_TEXTURE));
	}
}
