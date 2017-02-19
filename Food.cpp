#include "Food.h"
#include "Graphix.h"
#include "Shape.h"

Food::Food(int posX, int posY) : Shape(posX, posY)
{
}


Food::~Food()
{
}

void Food::Draw()
{
	DrawCircle(position.X, position.Y, 10);
}

void Food::SetPosition(int posX, int posY)
{
	position.X = posX;
	position.Y = posY;
}