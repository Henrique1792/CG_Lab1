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
}

void display(){
	cleanScreen();
	glPushMatrix();
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
			break;
	}
	currentMode=drawLINE;
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
	glPointSize(10);
	int i;
	GLint dx= (p2->x-p1->x);
	GLint dy= (p2->y-p1->y);
	GLint step,xInc, yInc;
	
	if(abs(dx)>abs(dy)){
		step=ceil(dy/dx);
		glBegin(GL_POINTS);
			for(xInc=p1->x, yInc=p1->y;
					xInc<p2->x && yInc<p2->y;
					xInc++, yInc+=step){
				glVertex2i(xInc,yInc);
			}
		glEnd();
	}
	else{
		step=ceil(dx/dy);
		glBegin(GL_POINTS);
			for(xInc=p1->x, yInc=p1->y;
					xInc<p2->x && yInc<p2->y;
					yInc++, xInc+=step){
				glVertex2i(xInc,yInc);
			}
		glEnd();
	}
	glFlush();
}
