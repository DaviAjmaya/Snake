#pragma once
#include "Body.h"
class Snake
{
public:
	Snake(int posX, int posY);
	~Snake();
	void Rotate(int dir);
	void Update(void);
	void Draw(void);
	void SetSpeed(float s);
	float GetSpeed(void);
	void AddBody(void);
private:
	float updateFreq;
	float snakeSpeed;
	float speed;
	int direction;
	Body **snake;
	int length;
};

