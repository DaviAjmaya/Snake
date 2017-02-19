#include "Snake.h"

Snake::Snake(int posX, int posY)
{
    srand(time(NULL));
	winX = posX;
	winY = posY;
	length = 3;
	snake = new Body*[length];
	snake[0] = new Body(winX/2, winY/2);
	snake[1] = new Body(winX/2 -20, winY/2);
	snake[2] = new Body(winX/2 - 40, winY/2);
	speed = 20.0f;
	direction = 3;
	updateFreq = 4;
	snakeSpeed = 0;
	finished = false;
	SpawnFood();
}


Snake::~Snake()
{
	for (int i = 1; i < length; i++)
	{
		delete[]snake[i];
	}
	delete[] snake;
}

void Snake::NewGame(int posX, int posY) 
{
	delete snake;
	winX = posX;
	winY = posY;
	length = 3;
	snake = new Body*[length];
	snake[0] = new Body(winX / 2, winY / 2);
	snake[1] = new Body(winX / 2 - 20, winY / 2);
	snake[2] = new Body(winX / 2 - 40, winY / 2);
	speed = 20.0f;
	direction = 3;
	updateFreq = 4;
	snakeSpeed = 0;
	finished = false;
	SpawnFood();
}

void Snake::SpawnFood()
{
	bool spawned = false;
	int x, y;
	while (!spawned)
	{
		spawned = true;
		// Get random pos for food
		x = rand() % (winX - 40) / 20;
		y = rand() % (winY - 40) / 20;
		
		// Make sure food doesn't spawn on the snake
		for (int i = 0; i < length; i++)
		{
			if (CheckCollision(snake[0]->GetPosition().X, snake[0]->GetPosition().Y, x, y))
			{
				spawned = false;
				break;
			}
		}
	}
	if (food == nullptr)
	{
		food = new Food(x*20+10, y*20+10);
	}
	else
	{
		food->SetPosition(x*20+10, y*20+10);
	}
}

void Snake::Update()
{
	int x, y;
	if (snakeSpeed >= updateFreq)
	{
		x = snake[0]->GetPosition().X;
		y = snake[0]->GetPosition().Y;
		snakeSpeed = 0;
		for (int i = length-1; i > 0; i--)
		{
			snake[i]->SetPosition(snake[i - 1]->GetPosition().X, snake[i - 1]->GetPosition().Y);
		}
		switch (direction)
		{
		case 0: // up
			snake[0]->SetPosition(x, y - speed);
			break;
		case 1: // left
			snake[0]->SetPosition(x - speed, y);
			break;
		case 2: // down
			snake[0]->SetPosition(x, y + speed);
			break;
		case 3: // right
			snake[0]->SetPosition(x + speed, y);
			break;
		}
		if (x < 20 && direction == 1)
		{
			snake[0]->SetPosition(winX-20, y);
		}
		if (x > winX-21 && direction == 3)
		{
			snake[0]->SetPosition(0, y);
		}
		if (y < 20 && direction == 0)
		{
			snake[0]->SetPosition(x, winY-20);
		}
		if (y > winY-21 && direction == 2)
		{
			snake[0]->SetPosition(x, 0);
		}

		FoodCollision();
		SnakeCollision();
	}

	snakeSpeed += 1;
}
void Snake::FoodCollision()
{
	// Food collision
	if (CheckCollision(snake[0]->GetPosition().X, snake[0]->GetPosition().Y, food->GetPosition().X, food->GetPosition().Y))
	{
		SpawnFood();
		AddBody();
	}
}

void Snake::SnakeCollision()
{
	// If head collides with body/tail
	for (int i = 1; i < length; i++)
	{
		if (CheckCollision(snake[0]->GetPosition().X, snake[0]->GetPosition().Y, snake[i]->GetPosition().X, snake[i]->GetPosition().Y))
		{
			finished = true;
		}
	}

}

bool Snake::CheckCollision(int x1, int y1, int x2, int y2)
{
	// Collision x-axis
	bool collX = x1 + 10 >= x2  && x2 + 5 >= x1;

	// Collision y-axis
	bool collY = y1 + 10 >= y2 && y2 + 5 >= y1;
	// Collision only if on both axes
	return collX && collY;
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
	food->Draw();
}

void Snake::AddBody()
{
	length += 1;
	Body **tmp = new Body*[length];
	tmp[0] = snake[0];
	tmp[1] = new Body(snake[1]->GetPosition().X, snake[1]->GetPosition().Y);
	for (int i = 2; i < length-1; i++)
	{
		tmp[i] = snake[i-1];
	}
	tmp[length - 1] = snake[length - 2];
	delete snake;
	snake = tmp;
	updateFreq *= 0.99;
}

void Snake::SetSpeed(float s)
{
	speed = s;
}

float Snake::GetSpeed()
{
	return speed;
}