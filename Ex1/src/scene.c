#include "../include/scene.h"
#include "../include/events.h"

//Extern Variables

int extern menuOption;
int extern xMouse, yMouse;
int extern xMenu, yMenu;
DOT extern *p1, *p2;

//global Variable
eMode extern currentMode;


/*
 * drawing
 *
*/
void drawShapes(){
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	//Drawing Menu Options
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
		case(DRAW_IDLE):
			printf("waiting selection...\n");
			break;
	}
	currentMode=DRAW_IDLE;
}
void drawLoop(){
	//Load background color and object color
	glClearColor(1.0,1.0,1.0,0.0);
	glColor3f(0.0,0.0,0.0);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	drawShapes();
	glutSwapBuffers();
}
/*
 * Menu Structure - Skeleton
 *
 *
*/
void menuSkeleton(int Item){
	if(Item!=DRAW_IDLE){
		currentMode=Item;
		printf("Selected: %d\n",Item);
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
	printf("Initial point: %d %d\n", p1->x, p1->y);

}

