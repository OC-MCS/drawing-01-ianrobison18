#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include "Shape.h"
#include <iostream>
#include <fstream>

using namespace std;
using namespace sf;

// finish the ShapeMgr class.

class ShapeMgr
{
private:
	vector <DrawingShape*> shapes; //vector containing all of the drawn shapes

public:
	ShapeMgr();
	~ShapeMgr();
	void addShape(Vector2f pos, ShapeEnum whichShape, Color color);
	vector <DrawingShape*> getShapes();
	void fileRead(fstream &file);
	void fileWrite(fstream &file);
};
