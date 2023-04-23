#include "pch.h"
#include "Scene.h"

void Scene::Draw()
{
	auto y = 0.005f;
	auto z = 1.0f;
	glPointSize(2.0f);
	glBegin(GL_LINES);
	auto step = M_PI / 10000;

	for (float x = 0; x < 2 * M_PI; x += step)
	{
		//auto coef = (1 + sin(x + step)) * (1 + 0.9 * cos(8 * (x + step))) + (1 + 0.1 * cos(24 * (x + step)));
		//glVertex3f(coef * cos(x + step), coef * sin(x + step), z);
		glVertex3f(x + step, y, z);
		//coef = (1 + sin(x)) * (1 + 0.9 * cos(8 * x)) + (1 + 0.1 * cos(24 * x));
		
		//glVertex3f(coef * cos(x), coef * sin(x), z);
		glVertex3f(x, y, z);
	}
	glEnd();
}