#include "Shape.h"
using namespace std;

const int SIZE = 10;

/*===========================
Name: DrawingShape
Purpose: initialize object
Parameters: nothing
Returns: nothing
===========================*/
DrawingShape::DrawingShape()
{

}

/*===========================
Name: DrawingShape
Purpose: initialize object with parameters
Parameters: shape, color, pos
Returns: nothing
===========================*/
DrawingShape::DrawingShape(ShapeEnum shape, Color color, Vector2f pos)
{
	this->shape = shape;
	this->color = color;
	this->pos = pos;
}

//drawing shape getters
/*===========================
Name: getShape
Purpose: return shape
Parameters: nothing
Returns: shapeEnum
===========================*/
ShapeEnum DrawingShape::getShape()
{
	return shape;
}

/*===========================
Name: getColor
Purpose: return the color
Parameters: nothing
Returns: Color
===========================*/
Color DrawingShape::getColor()
{
	return color;
}

/*===========================
Name: getPos
Purpose: returns shape position
Parameters: nothing
Returns: position
===========================*/
Vector2f DrawingShape::getPos()
{
	return pos;
}

// Circle Class
/*===========================
Name: Circle
Purpose: initialize a circle
Parameters: shape, color, pos
Returns: nothing
===========================*/
Circle::Circle(ShapeEnum shape, Color color, Vector2f pos) : DrawingShape(shape, color, pos)
{
	circle.setRadius(SIZE);
	circle.setOutlineThickness(2);
}

/*===========================
Name: Draw
Purpose: sets circle data and draws it
Parameters: render window
Returns: nothing
===========================*/
void Circle::Draw(RenderWindow &win)
{
	//Sets circle data and draws it
	circle.setPosition(getPos());
	circle.setOutlineColor(getColor());
	circle.setFillColor(getColor());

	win.draw(circle);
}

//Circle getters
/*===========================
Name: getCircle
Purpose: gets the circleshape
Parameters: nothing
Returns: circleshape
===========================*/
CircleShape Circle::getCircle()
{
	return circle;
}

/*===========================
Name: getFileRecord
Purpose: returns a struct of circle data
Parameters: nothing
Returns: ShapeData
===========================*/
ShapeData Circle::getFileRecord()
{
	//gets data to write to file
	ShapeData circleData; //the struct for the circle's data
	circleData.shape = getShape();
	circleData.color = getColor();
	circleData.pos = getPos();

	return circleData;
}

// Square Class
/*===========================
Name: Square
Purpose: initializes a square
Parameters: shape, color, pos
Returns: nothing
===========================*/
Square::Square(ShapeEnum shape, Color color, Vector2f pos) : DrawingShape(shape, color, pos)
{
	square.setSize(Vector2f(SIZE, SIZE));
	square.setOutlineThickness(2);
}

/*===========================
Name: Draw
Purpose: draws a square
Parameters: renderwindow
Returns: nothing
===========================*/
void Square::Draw(RenderWindow &win)
{
	//Sets circle data and draws it
	square.setPosition(getPos());
	square.setOutlineColor(getColor());
	square.setFillColor(getColor());

	win.draw(square);
}

//Square getters
/*===========================
Name: getsquare
Purpose: returns square
Parameters: nothing
Returns: RectangleShape
===========================*/
RectangleShape Square::getSquare()
{
	return square;
}

/*===========================
Name: getFileRecord
Purpose: returns a struct of square data
Parameters: nothing
Returns: ShapeData
===========================*/
ShapeData Square::getFileRecord()
{
	//gets data to write to file
	ShapeData squareData; //the struct for the square's data
	squareData.shape = getShape();
	squareData.color = getColor();
	squareData.pos = getPos();

	return squareData;
}