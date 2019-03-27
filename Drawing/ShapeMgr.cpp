#include "ShapeMgr.h"
#include "Shape.h"
using namespace std;

ShapeMgr::ShapeMgr()
{
}

ShapeMgr::~ShapeMgr()
{
	for (int i = 0; i < shapes.size(); i++)
	{
		delete (shapes[i]);
	}
}
void ShapeMgr::addShape(Vector2f pos, ShapeEnum whichShape, Color color)
{
	DrawingShape *shape;

	if (whichShape == CIRCLE)
	{
		shape = new Circle(whichShape, color, pos);
	}
	else if (whichShape == SQUARE)
	{
		shape = new Square(whichShape, color, pos);
	}

	shapes.push_back(shape);
}

vector <DrawingShape*> ShapeMgr::getShapes()
{
	return shapes;
}

void ShapeMgr::fileRead(fstream &file)
{
	ShapeData shape;
	
	while (file.read(reinterpret_cast<char*>(&shape), sizeof(ShapeData)))
	{
		ShapeEnum s = shape.shape;
		Color color = shape.color;
		Vector2f pos = shape.pos;
		addShape(pos, s, color);
	}
}

void ShapeMgr::fileWrite(fstream &file)
{
	ShapeData data;

	int i = 0;
	while ( i < shapes.size() && file.write(reinterpret_cast<char*>(&(shapes[i]->getFileRecord())), sizeof(ShapeData)))
	{
		i++;
	}
}