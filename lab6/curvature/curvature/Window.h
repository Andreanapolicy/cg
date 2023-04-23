#pragma once
#include "BaseWindow.h"
#include "Shader.h"

class Window : public BaseWindow
{
public:
	Window(int w, int h, const char* title);

private:
	void InitShaders();


	void OnMouseButton(int button, int action, [[maybe_unused]] int mods) override;
	void OnMouseMove(double x, double y) override;
	void RotateCamera(double xAngleRadians, double yAngleRadians);
	void OnResize(int width, int height) override;
	void OnRunStart() override;
	void Draw(int width, int height) override;
	void SetupCameraMatrix();

	int m_destance_to_origin = 5;

	bool m_leftButtonPressed = false;
	glm::dvec2 m_mousePos = {};
	glm::dmat4x4 m_cameraMatrix = glm::lookAt(
		glm::dvec3{ 0.0, 0.0, m_destance_to_origin },
		glm::dvec3{ 0.0, 0.0, 0.0 },
		glm::dvec3{ 0.0, 1.0, 0.0 });

	
	CProgram m_program;
	CShader m_vertexShader;
};
