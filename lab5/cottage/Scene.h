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
	Cube m_cube;
	mutable CTexture2D m_texture;
};
