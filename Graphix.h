#pragma once

#include "glut.h"
#pragma comment(lib, "opengl32")
#pragma comment(lib, "glu32")
#pragma comment(lib, "glut32")


static bool invalidate = true;

void GraphInit(void);
void timerCB(int millisec);
void display(void);
void GetInput(unsigned char key, int x, int y);
void DrawLine(int x1, int y1, int x2, int y2 );
void DrawRectanle(int x, int y, int width, int height );
void FillRectanle(int x, int y, int width, int height );

void DrawCircle(int cx, int cy, int radius);

void SetColor(int r, int  g, int  b);
void Redraw();
void Draw();
