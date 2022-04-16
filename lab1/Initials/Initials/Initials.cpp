#include "./CSlide.h"
#include "./Ccanvas.h"
#include "./Color.h"
#include "./CRectangle.h"
#include "./CGroup.h"
#include "./CEllipse.h"
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Window/Event.hpp>
#include <windows.h>

std::shared_ptr<IShape> SetLetterD(Color color);
std::shared_ptr<IShape> SetLetterA(Color color);
std::shared_ptr<CSlide> CreateSlide();

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR pCmdLine, int nCmdShow)
{
	auto slide = CreateSlide();

	auto width = (unsigned int)slide->GetWidth();
	auto height = (unsigned int)slide->GetHeight();

	sf::RenderWindow renderWindow(sf::VideoMode(width, height), "Result");
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

	slide->InsertShape(SetLetterD(0xabf5f2FF), 0);
	//slide->InsertShape(SetLetterA(0xabf5f2FF), 0);
	//slide->InsertShape(SetLetterA(0xabf5f2FF), 0);
	return slide;
}

std::shared_ptr<IShape> SetLetterD(Color color)
{
	auto firstPart = std::make_shared<CRectangle>(PointD{ 253, 305 }, 26, 100);
	firstPart->GetFillStyle()->Enable();
	firstPart->GetFillStyle()->SetColor(color);
	firstPart->GetLineStyle()->Enable();
	firstPart->GetLineStyle()->SetColor(0xFFFFFFFF);

	auto secondPart = std::make_shared<CEllipse>(PointD{ 273, 255 }, 15, 50);
	secondPart->GetFillStyle()->Enable();
	secondPart->GetFillStyle()->SetColor(color);

	auto letterD = std::make_shared<CGroup>();
	letterD->InsertShape(firstPart, 0);
	letterD->InsertShape(secondPart, 1);

	return letterD;
}

std::shared_ptr<IShape> SetLetterA(Color color)
{
	auto firstPart = std::make_shared<CRectangle>(PointD{ 270, 305 }, 26, 100);
	firstPart->GetFillStyle()->Enable();
	firstPart->GetFillStyle()->SetColor(color);
	firstPart->GetLineStyle()->Enable();
	firstPart->GetLineStyle()->SetColor(0xFFFFFFFF);

	auto secondPart = std::make_shared<CRectangle>(PointD{ 296, 375 }, 100, 40);
	secondPart->GetFillStyle()->Enable();
	secondPart->GetFillStyle()->SetColor(color);
	secondPart->GetLineStyle()->Enable();
	secondPart->GetLineStyle()->SetColor(0xFFFFFFFF);

	auto thirdPart = std::make_shared<CRectangle>(PointD{ 270, 305 }, 26, 100);
	thirdPart->GetFillStyle()->Enable();
	thirdPart->GetFillStyle()->SetColor(color);
	thirdPart->GetLineStyle()->Enable();
	thirdPart->GetLineStyle()->SetColor(0xFFFFFFFF);

	auto letterA = std::make_shared<CGroup>();
	letterA->InsertShape(firstPart, 0);
	letterA->InsertShape(secondPart, 1);
	letterA->InsertShape(thirdPart, 2);

	return letterA;
}