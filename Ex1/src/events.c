#include "../include/events.h"

//Extern variables
int extern xMouse,yMouse, sMouse;
eMode extern menuOption;
DOT extern *p1, *p2;
/*
 * Events - Mouse
 *
 *
*/
void initDots(){
	p1=(DOT *)malloc(sizeof(DOT));
	p2=(DOT *)malloc(sizeof(DOT));
	p1->x=0, p1->y=0;
}

void freeDots(){
	free(p1);
	free(p2);
}

eMode extern currentMode;
int menuOpen=0;
void onClick(int bt, int state, int x, int y){
	if(bt==GLUT_RIGHT_BUTTON && state==GLUT_DOWN){
		if(!menuOpen){
			menuOpen=0;
		}else{
			menuOpen=1;
		}
	}
	if(bt==GLUT_LEFT_BUTTON && state==GLUT_DOWN && menuOpen){
		xMouse=x, yMouse=y;
		switch(menuOption){
			case(DRAW_LINE):
				p1->x=xMouse, p1->y=yMouse;
				printf("P1: %d %d\n", p1->x, p1->y);
				break;
		}
		
	}
}

void OnMouseMove(int x, int y) {
	if(sMouse==GLUT_DOWN) {
		p2->x = x;
		p2->y=VIEWPORT_Y-y;
		glutPostRedisplay();
	}
}
/*
 * Events - Keyboard
 *
 *
*/
void keyPressed(unsigned char key, int x, int y);
