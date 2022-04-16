#include "./CSlide.h"
#include "./Ccanvas.h"
#include "./Color.h"
#include "./CRectangle.h"
#include "./CGroup.h"
#include "./CEllipse.h"
#include "./windowFunctions.h"
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Window/Event.hpp>

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR pCmdLine, int nCmdShow)
{
	if (!RegisterWndClass(hInstance))
	{
		return 1;
	}
	
	HWND hMainWindow = CreateMainWindow(hInstance);
	if (hMainWindow == NULL)
	{
		return 1;
	}

	ShowWindow(hMainWindow, nCmdShow);
	UpdateWindow(hMainWindow);

	auto slide = CreateSlide();

	auto width = (unsigned int)slide->GetWidth();
	auto height = (unsigned int)slide->GetHeight();

	sf::RenderWindow renderWindow(hMainWindow);
	CCanvas canvas(renderWindow);

	while (renderWindow.isOpen())
	{
		sf::Event event;
		while (renderWindow.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				renderWindow.close();
		}

		renderWindow.clear();
		slide->Draw(canvas);
		renderWindow.display();
	}

	return 0;
}

std::shared_ptr<CSlide> CreateSlide()
{
	auto slide = std::make_shared<CSlide>(800, 600);

	slide->InsertShape(SetLetterD(0x14c3ccFF, { 0, 0 }), 0);
	slide->InsertShape(SetLetterA(0x66afdcFF, { 0, 0 }), 0);
	slide->InsertShape(SetLetterA(0x500286FF, { 70, 0 }), 0);
	return slide;
}

std::shared_ptr<IShape> SetLetterD(Color color, PointD bias)
{
	auto firstPart = std::make_shared<CRectangle>(PointD{ 253 + bias.x, 305 + bias.y }, 13, 100);
	firstPart->GetFillStyle()->Enable();
	firstPart->GetFillStyle()->SetColor(color);
	firstPart->GetLineStyle()->Enable();
	firstPart->GetLineStyle()->SetColor(0xFFFFFFFF);

	auto secondPart = std::make_shared<CEllipse>(PointD{ 270 + bias.x, 245 + bias.y }, 15, 55);
	secondPart->GetFillStyle()->Enable();
	secondPart->GetFillStyle()->SetColor(color);

	auto letterD = std::make_shared<CGroup>();
	letterD->InsertShape(firstPart, 0);
	letterD->InsertShape(secondPart, 1);

	return letterD;
}

std::shared_ptr<IShape> SetLetterA(Color color, PointD bias)
{
	auto firstPart = std::make_shared<CRectangle>(PointD{ 310 + bias.x, 305 + bias.y }, 6, 100);
	firstPart->GetFillStyle()->Enable();
	firstPart->GetFillStyle()->SetColor(color);
	firstPart->GetLineStyle()->Enable();
	firstPart->GetLineStyle()->SetColor(0xFFFFFFFF);

	auto secondPart = std::make_shared<CRectangle>(PointD{ 310 + bias.x, 305 + bias.y }, 40, 6);
	secondPart->GetFillStyle()->Enable();
	secondPart->GetFillStyle()->SetColor(color);
	secondPart->GetLineStyle()->Enable();
	secondPart->GetLineStyle()->SetColor(0xFFFFFFFF);

	auto thirdPart = std::make_shared<CRectangle>(PointD{ 350 + bias.x, 305 + bias.y }, 6, 100);
	thirdPart->GetFillStyle()->Enable();
	thirdPart->GetFillStyle()->SetColor(color);
	thirdPart->GetLineStyle()->Enable();
	thirdPart->GetLineStyle()->SetColor(0xFFFFFFFF);

	auto fourthPart = std::make_shared<CRectangle>(PointD{ 315 + bias.x, 335 + bias.y }, 40, 6);
	fourthPart->GetFillStyle()->Enable();
	fourthPart->GetFillStyle()->SetColor(color);
	fourthPart->GetLineStyle()->Enable();
	fourthPart->GetLineStyle()->SetColor(0xFFFFFFFF);

	auto letterA = std::make_shared<CGroup>();
	letterA->InsertShape(firstPart, 0);
	letterA->InsertShape(secondPart, 1);
	letterA->InsertShape(thirdPart, 2);
	letterA->InsertShape(fourthPart, 3);

	return letterA;
}