#pragma once
#include "Graphix.h"
#include "Shape.h"
class Body : public Shape
{
public:
	Body(int posX, int posY);
	~Body();
	void SetPosition(int x, int y);
	virtual void Draw();
};