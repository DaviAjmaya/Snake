#include "Head.h"
#include "Graphix.h"

Head::Head(int posX, int posY) : Shape(posX, posY)
{
	speed = 2.0f;
	direction = 3;
}


Head::~Head()
{
}

void Head::Update()
{
	switch (direction)
	{
	case 0 : // up
		position.Y -= speed;
		break;
	case 1: // left
		position.X -= speed;
		break;
	case 2: // down
		position.Y += speed;
		break;
	case 3: // right
		position.X += speed;
		break;
	}
}

void Head::Draw()
{
	DrawRectanle(position.X, position.Y, 20, 20);
	FillRectanle(position.X, position.Y, 20, 20);
}
void Head::Rotate(int dir)
{
	switch (dir)
	{
	case 0: //left arrow
		direction += 1;
		if (direction > 3)
		{
			direction = 0;
		}
		break;
	case 1: //right arrow
		direction -= 1;
		if (direction < 0)
		{
			direction = 3;
		}
		break;
	}
}
void Head::SetSpeed(float s)
{
	speed = s;
}

float Head::GetSpeed()
{
	return speed;
}