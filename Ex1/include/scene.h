#ifndef SCENE_H_
#define SCENE_H_
#include <GL/glut.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "../include/settings.h"


typedef struct DOT{
	int x, y;
}DOT;

void drawLoop();
void menuCreation();
void drawLine();
void drawTriangle();
void drawSquare();
void drawCircle();
void drawEliptic();




#endif
