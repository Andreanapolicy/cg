#pragma once
#include "Cube.h"
#include "Pyramid.h"
#include "Texture.h"

class Scene
{
public:
	void Draw() const;
	
	~Scene() = default;

private:
	std::shared_ptr<Cube> CreateCube(float size = 1) const;
	std::shared_ptr<Pyramid> CreatePyramid(Pyramid::PyramidSideSize&& size, float height) const;

	void DrawLand() const;
	void DrawHouseMainPart() const;
	void DrawHouseAdditionalPart() const;
	void DrawWindows() const;
	void DrawBalcony() const;
	void DrawDoor() const;
	void DrawGarade() const;
	void DrawRoof() const;

	void InitWoodTextureIfNeeded() const;
	void InitStoneTextureIfNeeded() const;
	void InitLandTextureIfNeeded() const;
	void InitDoorTextureIfNeeded() const;
	void InitSteelTextureIfNeeded() const;
	void InitGlassTextureIfNeeded() const;
	void InitGrassTextureIfNeeded() const;

	mutable CTexture2D m_woodTexture;
	mutable CTexture2D m_stoneTexture;
	mutable CTexture2D m_landTexture;
	mutable CTexture2D m_glassTexture;
	mutable CTexture2D m_doorTexture;
	mutable CTexture2D m_steelTexture;
	mutable CTexture2D m_grassTexture;
};
