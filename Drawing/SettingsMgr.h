#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include "Shape.h"
using namespace std;
using namespace sf;



// finish this code; add functions, data as needed
struct settings
{
	Color lastColor; //Last color used before leaving
	ShapeEnum lastShape; //Last shape used before leaving
};

class SettingsMgr
{
private:
	Color curColor; //current color used in the program
	ShapeEnum curShape; //current shape being used

public:
	SettingsMgr(Color startingColor, ShapeEnum startingShape);
	Color getCurColor();
	void setCurColor(Color curColor);
	ShapeEnum getCurShape();
	void setCurShape(ShapeEnum curShape);
	void fileWrite(fstream &file);
};
