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
	void DrawWindows() const;
	void DrawBalcony() const;
	void DrawDoor() const;
	void DrawGarade() const;

	mutable CTexture2D m_woodTexture;
	mutable CTexture2D m_stoneTexture;
	mutable CTexture2D m_landTexture;
	mutable CTexture2D m_glassTexture;
	mutable CTexture2D m_doorTexture;
	mutable CTexture2D m_steelTexture;
};
