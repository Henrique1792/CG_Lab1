#include "../include/events.h"

//Extern variables
int extern xMouse,yMouse, sMouse;
eMode extern menuOption;
DOT extern *p1, *p2, *p3, *p4;
eMode extern currentMode;
int lockP1=0, lockP2=0, lockP3=0, lockP4=0; 
int menuOpen=0;
/*
 * Events - Mouse
 *
 *
*/
void initDots(){
	p1=(DOT *)malloc(sizeof(DOT));
	p2=(DOT *)malloc(sizeof(DOT));
	p3=(DOT *)malloc(sizeof(DOT));
	p4=(DOT *)malloc(sizeof(DOT));
	p1->x=0, p1->y=0;
	p2->x=0, p2->y=0;
	p3->x=0, p3->y=0;
	p4->x=0, p4->y=0;
}

void freeDots(){
	free(p1);
	free(p2);
	free(p3);
	free(p4);
}

void onClick(int bt, int state, int x, int y){
	if(bt==GLUT_LEFT_BUTTON && state==GLUT_DOWN ){
		if(!lockP1){
			p1->x=x;
			p1->y=y;
			lockP1=1;
		}else{
			if(menuOption==DRAW_LINE && !lockP2){
				p2->x=x;
				p2->y=y;
				lockP1=0;
				lockP2=1;
				drawLine(p1,p2); 
			}
		}
		glutSwapBuffers();
	}
}

void OnMouseMove(int x, int y) {
}
/*
 * Events - Keyboard
 *
 *
*/
void keyPressed(unsigned char key, int x, int y);
