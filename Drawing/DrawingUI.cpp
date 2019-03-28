#include <SFML/Graphics.hpp>
#include <iostream>
using namespace std;
using namespace sf;
#include "DrawingUI.h"
#include "ShapeMgr.h"

/*===========================
Name: DrawingUI Constructor
Purpose: initialize object
Parameters: position vector
Returns: nothing
===========================*/
DrawingUI::DrawingUI(Vector2f p)
{
	//sets data for the drawing area to be drawn later
	drawingArea.setPosition(p);
	drawingArea.setOutlineColor(Color::White);
	drawingArea.setFillColor(Color::Black);
	drawingArea.setOutlineThickness(5);
	drawingArea.setSize(Vector2f(545, 500));
}

/*===========================
Name: Draw
Purpose: draws shapes from shapes manager
Parameters: render window, pointer to shapeMgr
Returns: nothing
===========================*/
void DrawingUI::draw(RenderWindow& win, ShapeMgr *mgr)
{
	//Draws all the shapes the user creates
	vector <DrawingShape*> shapes = mgr->getShapes(); //a temporary pointer to all the shapes
	win.draw(drawingArea);
	
	if (shapes.size() != 0)
	{
		for (int i = 0; i < shapes.size(); i++)
		{
			shapes[i]->Draw(win);
		}
	}
}

/*===========================
Name: Is Mouse in Canvas? 
Purpose: check if mouse is in canvas
Parameters: mouse position 
Returns: a bool telling if mouse is in or not
===========================*/
bool DrawingUI::isMouseInCanvas(Vector2f mousePos)
{
	//checks if mouse is in canvas
	bool isIn = false; //bool variable checking if mouse is in canvas
	if (drawingArea.getGlobalBounds().contains(mousePos))
	{
		isIn = true;
	}

	return isIn;
}