#ifndef SETTINGS_H_
#define SETTINGS_H_
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <GL/glut.h>

/*
 *
 * Defines goes here!
 *
 *
*/

#define SCREEN_SIZEX 1366
#define SCREEN_SIZEY 768
#define VIEWPORT_X 800
#define VIEWPORT_Y 600
#define ORTHO_X 400
#define ORTHO_Y 300

typedef enum dMode{
	drawIDLE,
	drawLINE,
	drawTRI,
	drawSQUA,
	drawCIRC,
	drawELIP 
}dMode;

typedef struct DOT{
	int x, y;

}DOT;
/*
 * Globals Goes here!
 *
*/


dMode currentMode;
int xMouse, yMouse, sMouse,bMouse;
int lockP1, lockLine, lockTri;
int dragging;
DOT *p1, *p2, *p3, *p4;

/*
 * inits
*/
#endif
