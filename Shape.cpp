#include "Shape.h"

Shape::Shape(int posX, int posY)
{
	position.X = posX;
	position.Y = posY;
}


Shape::~Shape(void)
{
}

Point Shape::GetPosition()
{
	return position;
}

