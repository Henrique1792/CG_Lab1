#include "../include/events.h"


int extern xMouse,yMouse;

/*
 * Events - Mouse
 *
 *
*/
void onClick(int bt, int state, int x, int y){
	xMouse=x,yMouse=y;
	if(bt==GLUT_LEFT_BUTTON && state==GLUT_DOWN)
		printf("Clicked at %d %d",xMouse, yMouse);

}
/*
 * Events - Keyboard
 *
 *
*/
void keyPressed(unsigned char key, int x, int y);
