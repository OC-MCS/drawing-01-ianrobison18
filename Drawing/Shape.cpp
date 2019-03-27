#include "Shape.h"
using namespace std;

const int SIZE = 10;

DrawingShape::DrawingShape()
{

}

DrawingShape::DrawingShape(ShapeEnum shape, Color color, Vector2f pos)
{
	this->shape = shape;
	this->color = color;
	this->pos = pos;
}

ShapeEnum DrawingShape::getShape()
{
	return shape;
}
Color DrawingShape::getColor()
{
	return color;
}
Vector2f DrawingShape::getPos()
{
	return pos;
}

// Circle Class
Circle::Circle(ShapeEnum shape, Color color, Vector2f pos) : DrawingShape(shape, color, pos)
{
	circle.setRadius(SIZE);
	circle.setOutlineThickness(2);
}

void Circle::Draw(RenderWindow &win)
{
	circle.setPosition(getPos());
	circle.setOutlineColor(getColor());
	circle.setFillColor(getColor());


	win.draw(circle);
}

CircleShape Circle::getCircle()
{
	return circle;
}

ShapeData Circle::getFileRecord()
{
	ShapeData circleData;
	circleData.shape = getShape();
	circleData.color = getColor();
	circleData.pos = getPos();

	return circleData;
}

// Square Class
Square::Square(ShapeEnum shape, Color color, Vector2f pos) : DrawingShape(shape, color, pos)
{
	square.setSize(Vector2f(SIZE, SIZE));
	square.setOutlineThickness(2);
}

void Square::Draw(RenderWindow &win)
{
	square.setPosition(getPos());
	square.setOutlineColor(getColor());
	square.setFillColor(getColor());

	win.draw(square);
}

RectangleShape Square::getSquare()
{
	return square;
}

ShapeData Square::getFileRecord()
{
	ShapeData squareData;
	squareData.shape = getShape();
	squareData.color = getColor();
	squareData.pos = getPos();

	return squareData;
}