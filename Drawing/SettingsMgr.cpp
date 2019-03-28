#include <SFML/Graphics.hpp>
#include <iostream>
#include <fstream>
#include "Shape.h"
#include "SettingsMgr.h"
using namespace std;
using namespace sf;

/*===========================
Name: SettingsMgr
Purpose: initializes settings
Parameters: starting color and shape
Returns: nothing
===========================*/
SettingsMgr::SettingsMgr(Color startingColor, ShapeEnum startingShape)
{
	curColor = startingColor;
	curShape = startingShape;
}

//getters and setters
/*===========================
Name: getCurColor
Purpose: returns current color
Parameters: nothing
Returns: current color
===========================*/
Color SettingsMgr::getCurColor()
{
	return curColor; // just to make it compile 
}

/*===========================
Name: setCurColor
Purpose: sets the color
Parameters: color
Returns: nothing
===========================*/
void SettingsMgr::setCurColor(Color curColor)
{
	this->curColor = curColor;
}

/*===========================
Name: getcurShape
Purpose: returns the current shape
Parameters: nothing
Returns: shape
===========================*/
ShapeEnum SettingsMgr::getCurShape()
{
	return curShape; // just to make it compile;
}

/*===========================
Name: setCurShape
Purpose: sets a new shape
Parameters: shape
Returns: nothing
===========================*/
void SettingsMgr::setCurShape(ShapeEnum curShape)
{
	this->curShape = curShape;
}


/*===========================
Name: fileWrite
Purpose: writes settings to a file
Parameters: file
Returns: nothing
===========================*/
void SettingsMgr::fileWrite(fstream &file)
{
	//writes settings to file
	settings lastSettings = { curColor, curShape };

	file.write(reinterpret_cast<char*>(&lastSettings), sizeof(settings));
}