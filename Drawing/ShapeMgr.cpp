#include "ShapeMgr.h"
#include "Shape.h"
using namespace std;

/*===========================
Name: ShapeMgr
Purpose: default constructor
Parameters: nothing
Returns: nothing
===========================*/
ShapeMgr::ShapeMgr()
{
}

/*===========================
Name: ~ShapeMgr
Purpose: destroy shapes vector
Parameters: nothing
Returns: nothing
===========================*/
ShapeMgr::~ShapeMgr()
{
	//deletes shapes vector
	for (int i = 0; i < shapes.size(); i++)
	{
		delete (shapes[i]);
	}
}

/*===========================
Name: Add Shape
Purpose: add a shape to the shapes vector
Parameters: position, shape, and color
Returns: nothing
===========================*/
void ShapeMgr::addShape(Vector2f pos, ShapeEnum whichShape, Color color)
{
	//checks shape and adds it to vector based on the shape
	DrawingShape *shape; //a new pointer to a shape

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

//shapes getter
/*===========================
Name: getShapes
Purpose: return vector of pointers to shapes
Parameters: nothing
Returns: vector
===========================*/
vector <DrawingShape*> ShapeMgr::getShapes()
{
	return shapes;
}

/*===========================
Name: fileRead
Purpose: read shapes from file
Parameters: file reference
Returns: nothing
===========================*/
void ShapeMgr::fileRead(fstream &file)
{
	ShapeData shape; //a shape to read from the file
	//reads shapes from file
	while (file.read(reinterpret_cast<char*>(&shape), sizeof(ShapeData)))
	{
		ShapeEnum s = shape.shape;
		Color color = shape.color;
		Vector2f pos = shape.pos;
		addShape(pos, s, color);
	}
}

/*===========================
Name: File Write
Purpose: writes out shapes to a file
Parameters: file by reference
Returns: nothing
===========================*/
void ShapeMgr::fileWrite(fstream &file)
{
	ShapeData data; //a shape to write to file
	//writes shapes to file
	int i = 0;
	while ( i < shapes.size() && file.write(reinterpret_cast<char*>(&(shapes[i]->getFileRecord())), sizeof(ShapeData)))
	{
		i++;
	}
}