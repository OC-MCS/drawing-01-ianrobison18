#include <SFML/Graphics.hpp>
#include <iostream>
#include <fstream>
#include "Shape.h"
#include "SettingsMgr.h"
using namespace std;
using namespace sf;

SettingsMgr::SettingsMgr(Color startingColor, ShapeEnum startingShape)
{
	curColor = startingColor;
	curShape = startingShape;
}

Color SettingsMgr::getCurColor()
{
	return curColor; // just to make it compile 
}

void SettingsMgr::setCurColor(Color curColor)
{
	this->curColor = curColor;
}

ShapeEnum SettingsMgr::getCurShape()
{
	return curShape; // just to make it compile;
}

void SettingsMgr::setCurShape(ShapeEnum curShape)
{
	this->curShape = curShape;
}



void SettingsMgr::fileWrite(fstream &file)
{
	settings lastSettings = { curColor, curShape };

	file.write(reinterpret_cast<char*>(&lastSettings), sizeof(settings));
}