#include "Body.h"



Body::Body(int posX, int posY) : Shape(posX, posY)
{
}


Body::~Body()
{
}

void Body::SetPosition(int x, int y)
{
	position.X = x;
	position.Y = y;
}

void Body::Draw()
{
	DrawRectanle(position.X, position.Y, 20, 20);
	FillRectanle(position.X, position.Y, 20, 20);
}