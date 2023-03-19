#include "Ejik.h"
#include <glut.h>
#include <math.h>
#include <numbers>

namespace
{
void FillEllipse(float xCenter, float yCenter, float rx, float ry, int points)
{
	const float step = 2 * std::numbers::pi / points;

	glBegin(GL_TRIANGLE_FAN);

	glVertex2d(xCenter, yCenter);

	for (float angle = 0; angle <= 2 * std::numbers::pi; angle += step)
	{
		float a = (fabsf(angle - 2 * std::numbers::pi) < 1e-5) ? 0 : angle;
		const float dx = rx * cosf(a);
		const float dy = ry * sinf(a);
	
		glVertex2f(dx + xCenter, dy + yCenter);
	}

	glEnd();
}

void DrawBody()
{
	glColor3f(0.81, 0.14, 0.58);

	FillEllipse(200, 200, 80, 120, 360);

	FillEllipse(125, 250, 5, 8, 360); // ears
	FillEllipse(275, 250, 5, 8, 360); // ears

	glColor3f(0.56, 0.10, 0.41);
	
	glBegin(GL_TRIANGLE_FAN); // eyebrows
		glVertex2d(180, 280);
		glVertex2d(170, 270);
		glVertex2d(169, 278);
		glVertex2d(179, 287);
		glVertex2d(192, 293);
		glVertex2d(190, 284);
	glEnd();
	
	glBegin(GL_TRIANGLE_FAN); // eyebrows
		glVertex2d(220, 280);
		glVertex2d(230, 270);
		glVertex2d(231, 278);
		glVertex2d(221, 287);
		glVertex2d(208, 293);
		glVertex2d(210, 284);
	glEnd();

	glBegin(GL_TRIANGLE_STRIP); // nose
		glVertex2d(190, 200);
		glVertex2d(210, 200);
		glVertex2d(200, 190);
	glEnd();
	glBegin(GL_LINES);
		glVertex2d(200, 190);
		glVertex2d(200, 180);
	glEnd();

	glColor3f(0.22, 0.04, 0.16);
	glBegin(GL_TRIANGLE_STRIP); // mouth
		glVertex2d(190, 185);
		glVertex2d(200, 180);
		glVertex2d(200, 170);
		glVertex2d(210, 185);
	glEnd();
}

void DrawEyes()
{
}

void DrawHead()
{
}

void DrawHands()
{
}

void DrawLegs()
{
}

}


Ejik::Ejik()
{
}

void Ejik::Draw(float x, float y)
{
	glClear(GL_COLOR_BUFFER_BIT);

	glPointSize(2.0);

	DrawBody();
	
	glFlush();
}
