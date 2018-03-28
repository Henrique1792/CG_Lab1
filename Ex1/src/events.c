#include "../include/events.h"

//Extern variables
int extern xMouse,yMouse, sMouse;
eMode extern menuOption;
DOT extern p1, p2;
/*
 * Events - Mouse
 *
 *
*/
eMode extern currentMode;
void onClick(int bt, int state, int x, int y){
	xMouse=x, yMouse=y;
	if(bt==GLUT_LEFT_BUTTON && state==GLUT_DOWN){
		switch(menuOption){
			case(DRAW_LINE):
				p1.x=xMouse, p1.y=y;
				printf("P1: %d %d\n", p1.x, p1.y);
				break;
		}
		
	}
}

void OnMouseMove(int x, int y) {
	if(sMouse==GLUT_DOWN) {
		p2.x = x;
		p2.y=VIEWPORT_Y-y;
		glutPostRedisplay();
	}
}
/*
 * Events - Keyboard
 *
 *
*/
void keyPressed(unsigned char key, int x, int y);
