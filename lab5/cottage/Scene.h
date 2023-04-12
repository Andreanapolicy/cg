#pragma once
#include "Cube.h"
#include "Texture.h"

class Scene
{
public:
	Scene();
	
	void Draw() const;
	
	~Scene() = default;

private:
	void DrawLand() const;


	Cube m_cube;
	mutable CTexture2D m_woodTexture;
	mutable CTexture2D m_stoneTexture;
	mutable CTexture2D m_landTexture;
};
