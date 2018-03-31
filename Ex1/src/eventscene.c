#include "../include/eventscene.h"


/*************GLOBALS**************/ 

dMode extern currentMode;
int extern lockP1;
DOT extern *p1, *p2;

/*************DISPLAY**************/ 
void cleanScreen(){ 
	glClearColor(1.0, 1.0, 1.0, 0.0);
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(0.0,0.0,0.0);
	glLoadIdentity();
}

void display(){
	cleanScreen();

	switch(currentMode){
		case(drawLINE):
			drawLine(p1, p2);
			break;
		case(drawTRI):
			break;
		case(drawSQUA):
			break;
		case(drawCIRC):
			break;
		case(drawELIP):
			break;
		case(drawIDLE):
			printf("nothing/transform\n");
	}
	glutSwapBuffers();
}


/*************DRAWS**************/

void drawLine(DOT *p1, DOT *p2){
	glPointSize(50);
	printf("dot1: %f %f\n", p1->x, p1->y);
	printf("dot2: %f %f\n", p2->x, p2->y);

	glBegin(GL_POINTS);
		glVertex2f(p1->x, p1->y);
		glVertex2f(p2->x, p2->y);
	glEnd();
	glFlush();
}



/*************EVENTS**************/

void onClick(int bt, int state, int x, int y){
	xMouse=x, yMouse=y, sMouse=state;
	if(bt==GLUT_LEFT_BUTTON && state==GLUT_DOWN){
		if(!lockP1){
			p1->x=xMouse, p1->y=yMouse;
			lockP1=1;
		}
		else{
			p2->x=xMouse, p2->y=yMouse;
			lockP1=0;
		}
	}
	glutPostRedisplay();
}
