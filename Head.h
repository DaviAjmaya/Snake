#pragma once
#include "Shape.h"
class Head : public Shape
{
public:
	Head(int posX, int posY);
	~Head();
	void Rotate(int dir);
	virtual void Update();
	virtual void Draw();
	void SetSpeed(float s);
	float GetSpeed();
protected:
	float speed;
	int direction;
};

