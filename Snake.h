#pragma once
#include "Body.h"
#include "Food.h"
#include <stdlib.h>
#include <time.h>
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
	bool finished;
	void NewGame(int posX, int posY);
private:
	float updateFreq;
	float snakeSpeed;
	float speed;
	int direction;
	Body **snake;
	Food *food = NULL;
	int length;
	void SnakeCollision(void);
	void FoodCollision(void);
	bool CheckCollision(int x1, int y1, int x2, int y2);
	int winX, winY;
	void SpawnFood(void);
};

