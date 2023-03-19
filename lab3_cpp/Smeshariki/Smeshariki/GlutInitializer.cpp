#include "GlutInitializer.h"
#include <glut.h>

namespace
{

void myInit(void)
{
	glClearColor(1.0, 0.5, 0.0, 1.0);

	glMatrixMode(GL_PROJECTION);

	glLoadIdentity();

	gluOrtho2D(0.0, 400.0, 0.0, 400.0);
}

}

GlutInitializer::GlutInitializer(int argc, char** argv, void (*func)(void))
{
	glutInit(&argc, argv);

	glutInitDisplayMode(
		GLUT_SINGLE | GLUT_RGB);

	glutInitWindowSize(1200, 740);

	glutInitWindowPosition(0, 0);

	glutCreateWindow("Ejik");
	glutDisplayFunc(func);
	myInit();

	glutMainLoop();
}
