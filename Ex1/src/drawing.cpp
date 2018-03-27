#include "../include/drawing.h"

/*
 * Function to display screen
 *
 */
int extern menuValue;
GLint extern xMouse, yMouse, sMouse, bt;
void display(){
	glClearColor(1.0,1.0,1.0,0.0); // set background color
	glClear(GL_COLOR_BUFFER_BIT); //reset color buffer
	glColor3f(0.0,0.0,0.0);
	glLoadIdentity(); //Load Identity matrix to reset drawing locations
	switch(menuValue){
		case(1):
			glPushMatrix();
			drawLine();
			glPopMatrix();
			break;
	
		case(2):
			glPushMatrix();
			drawTriangle();
			glPopMatrix();
			break;
	
		case(3):
			glPushMatrix();
			drawSquare();
			glPopMatrix();
			break;

		case(4):
			glPushMatrix();
			drawCircle();
			glPopMatrix();
			break;
	
		case(5):
			glPushMatrix();
			drawElipse();
			glPopMatrix();
			break;
	}
        glFlush(); 
}
void drawLine(DOT p1, DOT p2){
	GLint dx, dy, step;
	dx=abs(p2.x - p1.x);
	dy=abs(p2.y - p1.y);
	
	glBegin(GL_POINTS);
		glVertex2i(xMouse, yMouse);
	glEnd();
}
void drawTriangle();
void drawSquare();

//Note about Circle: user drag mouse and it determines it's size
//with
//	((xf-xc)²+(yf-yc)²)^1/2
void drawCircle();
void drawElipse();
