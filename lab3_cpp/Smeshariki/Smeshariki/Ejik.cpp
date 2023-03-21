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
	glColor3f(0.188, 0.153, 0.274);

	FillEllipse(170, 220, 30, 50, 360);
	FillEllipse(230, 220, 30, 50, 360);

	glBegin(GL_TRIANGLE_STRIP);
		glVertex2d(250, 230);
		glVertex2d(275, 260);
		glVertex2d(255, 225);
		glVertex2d(275, 235);
	glEnd();

	glBegin(GL_TRIANGLE_STRIP);
		glVertex2d(150, 230);
		glVertex2d(125, 260);
		glVertex2d(145, 225);
		glVertex2d(125, 235);
	glEnd();

	
	glColor3f(255, 255, 255);

	FillEllipse(170, 220, 21, 35, 360);
	FillEllipse(230, 220, 21, 35, 360);

	
	glColor3f(0, 0, 0);

	FillEllipse(180, 215, 10, 20, 360);
	FillEllipse(220, 215, 10, 20, 360);
}

void DrawHead()
{
	glColor3f(0.28, 0.18, 0.53);
		
	glBegin(GL_TRIANGLE_FAN);
		glVertex2d(200, 100);

		glVertex2d(90, 260);
		glVertex2d(120, 280);
		glVertex2d(122, 337);
		glVertex2d(150, 320);
		glVertex2d(170, 370);
		glVertex2d(190, 340);
		glVertex2d(208, 380);
		glVertex2d(220, 334);
		glVertex2d(253, 361);
		glVertex2d(248, 312);
		glVertex2d(287, 323);
		glVertex2d(275, 280);
		glVertex2d(310, 260);
	glEnd();
}

void DrawHands()
{
	glColor3f(0.81, 0.14, 0.58);

	glBegin(GL_TRIANGLE_STRIP);
		glVertex2d(275, 175);
		glVertex2d(290, 175);
		glVertex2d(275, 185);

		glVertex2d(290, 185);
		glVertex2d(285, 185);
		glVertex2d(290, 150);
		glVertex2d(285, 150);
	glEnd();

	glBegin(GL_TRIANGLE_STRIP);
		glVertex2d(125, 175);
		glVertex2d(110, 175);
		glVertex2d(125, 185);

		glVertex2d(110, 185);
		glVertex2d(115, 185);
		glVertex2d(110, 150);
		glVertex2d(115, 150);
	glEnd();
}

void DrawLegs()
{
	glColor3f(0.81, 0.14, 0.58);

	glBegin(GL_TRIANGLE_STRIP);
		glVertex2d(220, 100);
		glVertex2d(230, 100);
		glVertex2d(220, 40);

		glVertex2d(230, 40);
		glVertex2d(230, 60);
		glVertex2d(240, 40);
	glEnd();

	glBegin(GL_TRIANGLE_STRIP);
		glVertex2d(180, 100);
		glVertex2d(170, 100);
		glVertex2d(180, 40);

		glVertex2d(170, 40);
		glVertex2d(170, 60);
		glVertex2d(160, 40);
	glEnd();
}

}


Ejik::Ejik()
{
}

void Ejik::Draw(float x, float y)
{
	glClear(GL_COLOR_BUFFER_BIT);

	glPointSize(2.0);

	DrawHead();
	DrawBody();
	DrawEyes();
	DrawHands();
	DrawLegs();
	
	glFlush();
}
