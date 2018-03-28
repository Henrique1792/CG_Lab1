#include "../include/scene.h"
#include "../include/events.h"

//Extern Variables

int extern menuOption;
int extern xMouse, yMouse;
int extern xMenu, yMenu;


//global Variable
int extern receiveDOTS;
eMode extern currentMode;


/*
 * drawing
 *
*/
void drawLoop(){
	//Load background color and object color
	glClearColor(1.0,1.0,1.0,0.0);
	glColor3f(0.0,0.0,0.0);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	//Drawing Menu Options
	glPushMatrix();
	switch(currentMode){
		case(DRAW_LINE):
			drawLine();
			break;
		case(DRAW_TRIANGLE):
			/*drawTriangle();*/
			break;
		case(DRAW_SQUARE):
			/*drawSquare();*/
			break;
		case(DRAW_CIRCLE):
			/*drawCircle();*/
			break;
		case(DRAW_ELIPTIC):
			/*drawEliptic();*/
			break;
		case(IDLE):
			printf("waiting selection...\n");
	}
	menuOption=0;
	glPopMatrix();
	glutSwapBuffers();
}
/*
 * Menu Structure - Skeleton
 *
 *
*/
void menuSkeleton(int Item){
	if(Item!=IDLE){
		currentMode=Item;
		printf("Selected: %d\n",Item);
		receiveDOTS=1;
	}
	else{
		printf("No option selected\n");
	}

	glutPostRedisplay();
}

/*
 * m
 * Menu Structure - trigger Creation
 *
 *
*/

void menuCreation(){
	int menid=glutCreateMenu(menuSkeleton);
	glutAddMenuEntry("Linha",DRAW_LINE);
	glutAddMenuEntry("Triangulo",DRAW_TRIANGLE);
	glutAddMenuEntry("Quadrado",DRAW_SQUARE);
	glutAddMenuEntry("Circulo",DRAW_CIRCLE);
	glutAddMenuEntry("Elipse",DRAW_ELIPTIC);

	glutAttachMenu(GLUT_RIGHT_BUTTON); 
}

void drawLine(){
	int x1, y1;
	if(receiveDOTS){
		x1=xMouse, y1=yMouse;
		printf("Initial point: %d %d\n", x1, y1);
	}

}

