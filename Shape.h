#pragma once
#include "Structs.h"
class Shape
{
public:
	Shape(int posX, int posY);
	~Shape(void);
	virtual void Draw() = 0;
	Point GetPosition();

protected:
	Point position;
};
