#pragma once
#include "Structs.h"

class Shape
{
public:
	Shape(int posX, int posY);
	~Shape(void);

	virtual void Draw() = 0;
	virtual void Update()
	{}
	Point GetPosition();

protected:
	Point position;
};
