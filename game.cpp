#include "stdafx.h"
#include <stdlib.h>
#include <math.h>
#include <time.h> 
#include "Graphix.h"
#include "Snake.h"

static bool finished = false;
Snake *s;
int windowSizeX = 800, windowSizeY = 600;
int input = 3;

// Get user input for movement
void GetInput(int key, int x, int y)
{
	switch (key)
	{
	case GLUT_KEY_LEFT: // rotate left
		s->Rotate(0);
		break;
	case GLUT_KEY_RIGHT: // rotate right 
		s->Rotate(1);
		break;
	case GLUT_KEY_F1: // Restart game
		s->NewGame(windowSizeX, windowSizeY);
		break;
	}
}
int _tmain(int argc, char** argv)
{
	s = new Snake(windowSizeX, windowSizeY);

	// initialize glut
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(windowSizeX, windowSizeY);
	glutInitWindowPosition(100, 4);
	glutCreateWindow("Snake");

	// initialize graphics 
	GraphInit();
	glutDisplayFunc(display);
	glutTimerFunc(33, timerCB, 33);
	glutSpecialUpFunc(GetInput);
	glutMainLoop();
    return 0;
}

void Draw()
{
	if (!s->finished) // Update as long as game is not finished
	{
		s->Update();
	}
	s->Draw();
	Redraw();
}

