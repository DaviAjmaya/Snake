#pragma once
#include "Shape.h"
class Body : public Shape
{
public:
	Body(int posX, int posY);
	~Body();
	void SetPosition(int x, int y);
};