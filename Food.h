#pragma once
#include "Shape.h"
class Food : public Shape
{
public:
	Food(int posX, int posY);
	~Food();
	void Draw(void);
	void SetPosition(int posX, int posY);
};

