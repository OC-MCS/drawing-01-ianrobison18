#pragma once
#include <SFML/Graphics.hpp>
#include <string>
using namespace std;
using namespace sf;

// finish this code; add functions, classes, data as needed
enum ShapeEnum { CIRCLE, SQUARE };
struct ShapeData
{
	ShapeEnum shape;
	Color color;
	Vector2f pos;
};

// DrawingShape should be an abstract base class 
// for Circle and Square
class DrawingShape 
{
private:
	ShapeEnum shape;
	Color color;
	Vector2f pos;

public:
	DrawingShape();
	DrawingShape(ShapeEnum, Color, Vector2f);
	virtual void Draw(RenderWindow &win) = 0;
	virtual ShapeData getFileRecord() = 0;
	ShapeEnum getShape();
	Color getColor();
	Vector2f getPos();
};

// add Circle, Square classes below. These are derived from DrawingShape
class Circle : public DrawingShape
{
private:
	CircleShape circle;

public:
	Circle(ShapeEnum, Color, Vector2f);
	void Draw(RenderWindow &win);
	ShapeData getFileRecord();
	CircleShape getCircle();
};

class Square : public DrawingShape
{
private:
	RectangleShape square;

public:
	Square(ShapeEnum, Color, Vector2f);
	void Draw(RenderWindow &win);
	ShapeData getFileRecord();
	RectangleShape getSquare();
};