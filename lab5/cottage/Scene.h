#pragma once
#include "Cube.h"
#include "Texture.h"

class Scene
{
public:
	void Draw() const;
	
	~Scene() = default;

private:
	std::shared_ptr<Cube> CreateCube(float size = 1) const;
	void DrawLand() const;
	void DrawHouseMainPart() const;
	void DrawHouseAdditionalPart() const;

	mutable CTexture2D m_woodTexture;
	mutable CTexture2D m_stoneTexture;
	mutable CTexture2D m_landTexture;
};
