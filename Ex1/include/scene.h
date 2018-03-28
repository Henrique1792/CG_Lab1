#ifndef SCENE_H_
#define SCENE_H_
#include <GL/glut.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "../include/settings.h"



void drawLoop();
void onClick(int x, int y, int action,int button); 
void keyPressed(unsigned char key, int x, int y);
void menuCreation();




#endif
