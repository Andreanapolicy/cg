#include "pch.h"
#include "GLFWInitializer.h"
#include "Window.h"

int main()
{
	GLFWInitializer initializer;

	Window window{ 800, 600, "curvature" };
	window.Run();
}
