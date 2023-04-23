#include "pch.h"
//#include "GLFWInitializer.h"
//#include "Window.h"
#include "CMyApplication.h"

//int main(int argc, char** argv)
//{
//	//GLFWInitializer initializer;
//
//	//Window window{ 800, 600, "curvature" };
//	
//	
//	
//	auto temp = glGetString(GL_SHADING_LANGUAGE_VERSION);
//	auto temp2 = glGetString(GL_VERSION);
//	auto temp1 = glGetString(GL_SHADING_LANGUAGE_VERSION);
//	//window.Run();
//}

int main(int argc, char* argv[])
{
	CMyApplication application("curvature", 800, 600, argc, argv);


	try
	{
		if (glewInit() != GLEW_OK)
		{
			throw std::runtime_error("Failed to initialize GLEW");
		}
		auto temp = glGetString(GL_SHADING_LANGUAGE_VERSION);
		auto temp2 = glGetString(GL_VERSION);
		auto temp1 = glGetString(GL_SHADING_LANGUAGE_VERSION); 
		application.MainLoop();
	}
	catch (std::exception const& e)
	{
		std::cout << e.what();
	}
	return 0;
}