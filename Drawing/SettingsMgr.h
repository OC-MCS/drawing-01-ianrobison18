#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include "Shape.h"
using namespace std;
using namespace sf;



// finish this code; add functions, data as needed
struct settings
{
	Color lastColor;
	ShapeEnum lastShape;
};

class SettingsMgr
{
private:
	Color curColor;
	ShapeEnum curShape;

public:
	SettingsMgr(Color startingColor, ShapeEnum startingShape);
	Color getCurColor();
	void setCurColor(Color curColor);
	ShapeEnum getCurShape();
	void setCurShape(ShapeEnum curShape);
	void fileWrite(fstream &file);
};
