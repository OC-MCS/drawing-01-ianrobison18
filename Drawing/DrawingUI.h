#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
using namespace std;
using namespace sf;
#include "ShapeMgr.h"

// finish this code; add functions, data as needed

class DrawingUI
{
private:
	RectangleShape drawingArea; //The canvas area

public:
	DrawingUI(Vector2f p);
	void draw(RenderWindow& win, ShapeMgr *mgr);
	bool isMouseInCanvas(Vector2f mousePos);

};

