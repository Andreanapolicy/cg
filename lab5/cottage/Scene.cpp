#include "pch.h"
#include "Scene.h"
#include "CTextureLoader.h"
#include "Cube.h"
#include "Pyramid.h"
#include "TextureResourceName.h"

namespace
{
std::shared_ptr<Cube> CreateCube(float size)
{
	auto cube = std::make_shared<Cube>(size);
	cube->SetSpecularColor({ 1, 1, 1, 1 });
	cube->SetShininess(4.0f);

	return cube;
}

std::shared_ptr<Pyramid> CreatePyramid(Pyramid::PyramidSideSize&& size, float height)
{
	auto pyramid = std::make_shared<Pyramid>(std::move(size), height);
	pyramid->SetSpecularColor({ 1, 1, 1, 1 });
	pyramid->SetShininess(4.0f);

	return pyramid;
}
}

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

void Scene::DrawLand() const
{
	auto floor = CreateCube(1);

	auto landTexture = textureProvider.GetTexture(texture::name::LAND_TEXTURE);
	auto grassTexture = textureProvider.GetTexture(texture::name::GRASS_TEXTURE);
	glEnable(GL_TEXTURE_2D);
	
	for (auto indexI = -2.0f; indexI <= 2.0f; indexI += 1.0f)
	{
		for (auto indexJ = -2.0f; indexJ <= 2.0f; indexJ += 1.0f)
		{
			if ((int)indexI + (int)indexJ % 2 == 0)
			{
				landTexture->Bind();		
			}
			else
			{
				grassTexture->Bind();			
			}
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
	auto woodTexture = textureProvider.GetTexture(texture::name::WOOD_TEXTURE);
	glEnable(GL_TEXTURE_2D);
	woodTexture->Bind();

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
	auto woodTexture = textureProvider.GetTexture(texture::name::WOOD_TEXTURE);
	glEnable(GL_TEXTURE_2D);
	woodTexture->Bind();

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
	auto glassTexture = textureProvider.GetTexture(texture::name::GLASS_TEXTURE);
	glEnable(GL_TEXTURE_2D);
	glassTexture->Bind();

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
	auto stoneTexture = textureProvider.GetTexture(texture::name::STONES_TEXTURE);
	glEnable(GL_TEXTURE_2D);
	stoneTexture->Bind();

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
	auto doorTexture = textureProvider.GetTexture(texture::name::DOOR_TEXTURE);
	glEnable(GL_TEXTURE_2D);
	doorTexture->Bind();

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

	auto steelTexture = textureProvider.GetTexture(texture::name::STEEL_TEXTURE);

	glEnable(GL_TEXTURE_2D);
	steelTexture->Bind();

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
	auto woodTexture = textureProvider.GetTexture(texture::name::WOOD_TEXTURE);
	glEnable(GL_TEXTURE_2D);
	woodTexture->Bind();

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