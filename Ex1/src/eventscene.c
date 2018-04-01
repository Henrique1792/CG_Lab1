#include "../include/eventscene.h"


/*************GLOBALS**************/ 

dMode extern currentMode;
int extern lockP1;
DOT extern *p1, *p2;
int extern lockLine;
/*************DISPLAY**************/ 
void cleanScreen(){ 
	glClearColor(1.0, 1.0, 1.0, 0.0);
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(0.0,0.0,0.0);
	glPointSize(10);
}

void display(){
	cleanScreen();
	glPushMatrix();
	switch(currentMode){
		case(drawLINE):
			if(lockLine)
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
			break;
	}
	glPopMatrix();
	glutSwapBuffers();
}


/*************RESHAPE**************/
void reshape(int w, int h){
	//prevent divide by 0
	if(h==0) h=1;
	glViewport(0, 0, w, h);
	glMatrixMode(GL_PROJECTION);
	if(w<=h)
		gluOrtho2D (0.0f, ORTHO_X, 0.0f, ORTHO_Y*h/w);
	else
		gluOrtho2D (0.0f, ORTHO_X*w/h, 0.0f, ORTHO_Y);
} 
/*************DRAWS**************/

void drawLine(DOT *p1, DOT *p2){
	GLfloat dx = p2->x - p1->x;
	GLfloat dy = p2->y - p1->y;

	GLfloat x1 = p1->x;
	GLfloat y1 = p1->y;

	GLfloat step = 0;

	if(abs(dx) > abs(dy)) {
		step = abs(dx);
	} else {
		step = abs(dy);
	}

	GLfloat xInc = dx/step;
	GLfloat yInc = dy/step;

	glClear(GL_COLOR_BUFFER_BIT);
	glBegin(GL_POINTS);
	for(float i = 1; i <= step; i++) {
		glVertex2f(x1, y1);
		x1 += xInc;
		y1 += yInc;
	}
	glEnd();
	glFlush();
}
