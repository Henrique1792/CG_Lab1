#include "../include/eventscene.h"


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
		case(drawIDLE):
			printf("Nothing to do\n");
			break;
		case(drawLINE):
			if(lockLine)
				drawLine(p1,p2);
			break;
		case(drawTRI):
			if(lockTri)
				drawTri(p1,p2);
			break;
		case(drawSQR):
			if(lockSqr)
				drawSqr(p1,p2);
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

	if(abs(dx) > abs(dy))
		step = abs(dx);
	else 
		step = abs(dy);

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
void drawTri(DOT *p1, DOT *p2){
	int l=sqrt(pow((p2->x+p1->x),2)+pow((p2->y+p1->y),2))/2;
	p3->x=l/2;
	p3->y=l*(sqrt(3)/2);
	drawLine(p1,p2);
	drawLine(p2,p3);
	drawLine(p1,p3);
}


void drawSqr(DOT *p1, DOT *p2){
	p3->x=p1->x, p3->y=p2->y;
	p4->x=p2->x, p4->y=p1->y;

	drawLine(p1,p4);
	drawLine(p1,p3);
	drawLine(p2,p3);
	drawLine(p2,p4);
	glutPostRedisplay();
}
