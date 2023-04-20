#pragma once
#include "TextureProvider.h"

class Scene
{
public:
	void Draw() const;
	
	~Scene() = default;

private:
	void DrawHouseMainPart() const;
	void DrawHouseAdditionalPart() const;
	void DrawWindows() const;
	void DrawBalcony() const;
	void DrawDoor() const;
	void DrawGarade() const;
	void DrawRoof() const;

	TextureProvider textureProvider;
};
