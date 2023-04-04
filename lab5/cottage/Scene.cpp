#include "pch.h"
#include "Scene.h"
#include "Cube.h"

void Scene::Draw() const
{
	Cube cube;

	cube.SetSideColor(CubeSide::NEGATIVE_X, { 1, 1, 1, 1 });
	cube.SetSideColor(CubeSide::POSITIVE_X, { 1, 1, 1, 1 });
	cube.SetSideColor(CubeSide::NEGATIVE_Y, { 1, 1, 1, 1 });
	cube.SetSideColor(CubeSide::POSITIVE_Y, { 1, 1, 1, 1 });
	cube.SetSideColor(CubeSide::NEGATIVE_Z, { 1, 1, 1, 1 });
	cube.SetSideColor(CubeSide::POSITIVE_Z, { 1, 1, 1, 1 });
	cube.SetSpecularColor({ 1, 1, 1, 1 });
	cube.SetShininess(4.0f);
	cube.Draw();
}
