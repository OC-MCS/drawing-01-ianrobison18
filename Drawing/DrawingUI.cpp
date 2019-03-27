#include <SFML/Graphics.hpp>
#include <iostream>
using namespace std;
using namespace sf;
#include "DrawingUI.h"
#include "ShapeMgr.h"

DrawingUI::DrawingUI(Vector2f p)
{
	drawingArea.setPosition(p);
	drawingArea.setOutlineColor(Color::White);
	drawingArea.setFillColor(Color::Black);
	drawingArea.setOutlineThickness(5);
	drawingArea.setSize(Vector2f(545, 500));
}

void DrawingUI::draw(RenderWindow& win, ShapeMgr *mgr)
{
	vector <DrawingShape*> shapes = mgr->getShapes();
	win.draw(drawingArea);
	
	if (shapes.size() != 0)
	{
		for (int i = 0; i < shapes.size(); i++)
		{
			shapes[i]->Draw(win);
		}
	}
}

bool DrawingUI::isMouseInCanvas(Vector2f mousePos)
{
	bool isIn = false;
	if (drawingArea.getGlobalBounds().contains(mousePos))
	{
		isIn = true;
	}

	return isIn;
}