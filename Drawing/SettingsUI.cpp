#include <SFML/Graphics.hpp>
#include <iostream>
using namespace std;
using namespace sf;
#include "SettingsMgr.h"
#include "SettingsUI.h"

const int RAD = 20,
THICC = 2,
xpos = 65,
dY = 60;
int ypos = 60;

/*===========================
Name: SettingsUI
Purpose: Initializing buttones
Parameters: settingsMgr
Returns: nothing
===========================*/
SettingsUI::SettingsUI(SettingsMgr *mgr)
{
	//sets current colors and shapes
	if (mgr->getCurColor() == Color::Blue)
	{
		blueButton.setFillColor(Color::Blue);
		redButton.setFillColor(Color::Black);
		yellowButton.setFillColor(Color::Black);
	}
	else if (mgr->getCurColor() == Color::Red)
	{
		blueButton.setFillColor(Color::Black);
		redButton.setFillColor(Color::Red);
		yellowButton.setFillColor(Color::Black);
	}
	else if (mgr->getCurColor() == Color::Yellow)
	{
		blueButton.setFillColor(Color::Black);
		redButton.setFillColor(Color::Black);
		yellowButton.setFillColor(Color::Yellow);
	}

	if (mgr->getCurShape() == CIRCLE)
	{
		circleButton.setFillColor(Color::White);
		squareButton.setFillColor(Color::Black);
	}
	else if (mgr->getCurShape() == SQUARE)
	{
		circleButton.setFillColor(Color::Black);
		squareButton.setFillColor(Color::White);
	}
}

/*===========================
Name: handleMouseUp
Purpose: handles when the mouse clicks a button
Parameters: mouse pos, current settings
Returns: nothing
===========================*/
void SettingsUI::handleMouseUp(Vector2f mouse, SettingsMgr &settings)
{
	//draws buttons and sets color based on settings
	if (blueButton.getGlobalBounds().contains(mouse))
	{
		settings.setCurColor(Color::Blue);
		blueButton.setFillColor(Color::Blue);
		redButton.setFillColor(Color::Black);
		yellowButton.setFillColor(Color::Black);
	}
	else if (redButton.getGlobalBounds().contains(mouse))
	{
		settings.setCurColor(Color::Red);
		blueButton.setFillColor(Color::Black);
		redButton.setFillColor(Color::Red);
		yellowButton.setFillColor(Color::Black);
	}
	else if (yellowButton.getGlobalBounds().contains(mouse))
	{
		settings.setCurColor(Color::Yellow);
		blueButton.setFillColor(Color::Black);
		redButton.setFillColor(Color::Black);
		yellowButton.setFillColor(Color::Yellow);
	}

	if (circleButton.getGlobalBounds().contains(mouse))
	{
		settings.setCurShape(CIRCLE);
		circleButton.setFillColor(Color::White);
		squareButton.setFillColor(Color::Black);
	}
	else if (squareButton.getGlobalBounds().contains(mouse))
	{
		settings.setCurShape(SQUARE);
		circleButton.setFillColor(Color::Black);
		squareButton.setFillColor(Color::White);
	}
}

/*===========================
Name: Draw
Purpose: draws the settings area
Parameters: render window
Returns: nothing
===========================*/
void SettingsUI::draw(RenderWindow& win)
{
	//draws the settings area
	Font font; //font for the settings area
	font.loadFromFile("C:\\Windows\\Fonts\\comic.ttf");

	Text colorHeading("Drawing Colors", font, 20); //heading for the colors selection
	colorHeading.setPosition(30, 25);

	//draws the color buttons
	Vector2f pos(xpos, ypos); //position of buttons
	blueButton.setPosition(pos);
	blueButton.setRadius(RAD);
	blueButton.setOutlineThickness(THICC);
	blueButton.setOutlineColor(Color::Blue);
	
	pos.y += dY;
	redButton.setPosition(pos);
	redButton.setRadius(RAD);
	redButton.setOutlineThickness(THICC);
	redButton.setOutlineColor(Color::Red);

	pos.y += dY;
	yellowButton.setPosition(pos);
	yellowButton.setRadius(RAD);
	yellowButton.setOutlineThickness(THICC);
	yellowButton.setOutlineColor(Color::Yellow);

	pos.y += dY + 20;
	Text shapeHeading("Shape Select", font, 20); //heading for the shapes selection
	shapeHeading.setPosition(pos);

	//draws shape buttons
	pos.y += dY;
	circleButton.setPosition(pos);
	circleButton.setRadius(RAD);
	circleButton.setOutlineThickness(THICC);
	circleButton.setOutlineColor(Color::White);

	pos.y += dY;
	squareButton.setPosition(pos);
	squareButton.setSize(Vector2f(2*RAD, 2*RAD));
	squareButton.setOutlineThickness(THICC);
	squareButton.setOutlineColor(Color::White);

	//renders everything
	win.draw(colorHeading);
	win.draw(blueButton);
	win.draw(redButton);
	win.draw(yellowButton);
	win.draw(shapeHeading);
	win.draw(circleButton);
	win.draw(squareButton);
}