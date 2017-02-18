#include "stdafx.h"
#include <stdlib.h>
#include <math.h>
#include <time.h> 
#include "Graphix.h"
#include "Head.h"

Head *h;
int windowSizeX = 800, windowSizeY = 600;

void GetInput(int key, int x, int y)
{
	switch (key)
	{
	case GLUT_KEY_LEFT:
		h->Rotate(0);
		break;
	case GLUT_KEY_RIGHT:
		h->Rotate(1);
		break;
	}
}
int _tmain(int argc, char** argv)
{
	h = new Head(windowSizeX / 2, windowSizeY / 2);
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(windowSizeX, windowSizeY);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("Snake");
	GraphInit();
	glutDisplayFunc(display);
	glutTimerFunc(33, timerCB, 33);
	glutSpecialFunc(GetInput);
	glutMainLoop();
    return 0;
}

void Draw()
{
	h->Draw();
	h->Update();
	Redraw();
}

