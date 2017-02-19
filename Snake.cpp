#include "Snake.h"



Snake::Snake(int posX, int posY)
{
	length = 3;
	snake = new Body*[length];
	snake[0] = new Body(posX, posY);
	snake[1] = new Body(posX-20, posY);
	snake[2] = new Body(posX - 40, posY);
	speed = 20.0f;
	direction = 3;
	updateFreq = 4;
	snakeSpeed = 0;
}


Snake::~Snake()
{
	for (int i = 1; i < length; i++)
	{
		delete snake[i];
	}
}

void Snake::Update()
{
	if (snakeSpeed >= updateFreq)
	{
		snakeSpeed = 0;
		for (int i = length-1; i > 0; i--)
		{
			snake[i]->SetPosition(snake[i - 1]->GetPosition().X, snake[i - 1]->GetPosition().Y);
		}
		switch (direction)
		{
		case 0: // up
			snake[0]->SetPosition(snake[0]->GetPosition().X, snake[0]->GetPosition().Y - speed);
			break;
		case 1: // left
			snake[0]->SetPosition(snake[0]->GetPosition().X - speed, snake[0]->GetPosition().Y);
			break;
		case 2: // down
			snake[0]->SetPosition(snake[0]->GetPosition().X, snake[0]->GetPosition().Y + speed);
			break;
		case 3: // right
			snake[0]->SetPosition(snake[0]->GetPosition().X + speed, snake[0]->GetPosition().Y);
			break;
		}
	}

	snakeSpeed += 1;
}

void Snake::Rotate(int dir)
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

void Snake::Draw()
{
	for (int i = 0; i < length; i++)
	{
		snake[i]->Draw();
	}
}

void Snake::AddBody()
{

}

void Snake::SetSpeed(float s)
{
	speed = s;
}

float Snake::GetSpeed()
{
	return speed;
}