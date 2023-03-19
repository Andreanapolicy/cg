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
