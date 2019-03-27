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

SettingsUI::SettingsUI(SettingsMgr *mgr)
{
	if (mgr->getCurColor() == Color::Blue)
	{
		blueButton.setFillColor(Color::Blue);
		redButton.setFillColor(Color::Transparent);
		yellowButton.setFillColor(Color::Transparent);
	}
	else if (mgr->getCurColor() == Color::Red)
	{
		blueButton.setFillColor(Color::Transparent);
		redButton.setFillColor(Color::Red);
		yellowButton.setFillColor(Color::Transparent);
	}
	else if (mgr->getCurColor() == Color::Yellow)
	{
		blueButton.setFillColor(Color::Transparent);
		redButton.setFillColor(Color::Transparent);
		yellowButton.setFillColor(Color::Yellow);
	}

	if (mgr->getCurShape() == CIRCLE)
	{
		circleButton.setFillColor(Color::White);
		squareButton.setFillColor(Color::Transparent);
	}
	else if (mgr->getCurShape() == SQUARE)
	{
		circleButton.setFillColor(Color::Transparent);
		squareButton.setFillColor(Color::White);
	}
}

void SettingsUI::handleMouseUp(Vector2f mouse, SettingsMgr &settings)
{
	if (blueButton.getGlobalBounds().contains(mouse))
	{
		settings.setCurColor(Color::Blue);
		blueButton.setFillColor(Color::Blue);
		redButton.setFillColor(Color::Transparent);
		yellowButton.setFillColor(Color::Transparent);
	}
	else if (redButton.getGlobalBounds().contains(mouse))
	{
		settings.setCurColor(Color::Red);
		blueButton.setFillColor(Color::Transparent);
		redButton.setFillColor(Color::Red);
		yellowButton.setFillColor(Color::Transparent);
	}
	else if (yellowButton.getGlobalBounds().contains(mouse))
	{
		settings.setCurColor(Color::Yellow);
		blueButton.setFillColor(Color::Transparent);
		redButton.setFillColor(Color::Transparent);
		yellowButton.setFillColor(Color::Yellow);
	}

	if (circleButton.getGlobalBounds().contains(mouse))
	{
		settings.setCurShape(CIRCLE);
		circleButton.setFillColor(Color::White);
		squareButton.setFillColor(Color::Transparent);
	}
	else if (squareButton.getGlobalBounds().contains(mouse))
	{
		settings.setCurShape(SQUARE);
		circleButton.setFillColor(Color::Transparent);
		squareButton.setFillColor(Color::White);
	}
}

void SettingsUI::draw(RenderWindow& win)
{
	Font font;
	font.loadFromFile("C:\\Windows\\Fonts\\comic.ttf");

	Text colorHeading("Drawing Colors", font, 20);
	colorHeading.setPosition(30, 25);

	Vector2f pos(xpos, ypos);
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
	Text shapeHeading("Shape Select", font, 20);
	shapeHeading.setPosition(pos);

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

	win.draw(colorHeading);
	win.draw(blueButton);
	win.draw(redButton);
	win.draw(yellowButton);
	win.draw(shapeHeading);
	win.draw(circleButton);
	win.draw(squareButton);
}