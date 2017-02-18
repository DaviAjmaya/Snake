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
