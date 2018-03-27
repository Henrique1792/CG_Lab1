#ifndef DRAWING_H_
#define DRAWING_H_
#include "default.h"

void display();
void drawLine();
void drawTriangle();
void drawSquare();

//Note about Circle: user drag mouse and it determines it's size
//with
//	((xf-xc)²+(yf-yc)²)^1/2
void drawCircle();
void drawElipse();

#endif
