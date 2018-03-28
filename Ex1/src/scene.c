#include "../include/scene.h"
#include "../include/events.h"

//Extern Variables

int extern menuOption;
int extern xMouse, yMouse;
DOT  p1, p2;
/*
 * drawing
 *
*/
void drawLoop(){
	//Load background color and object color
	glClearColor(1.0,1.0,1.0,0.0);
	glColor3f(1.0,1.0,1.0);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	//Drawing Menu Options
	glPushMatrix();
	switch(menuOption){
		case(1):
			drawLine();
			break;
		case(2):
			/*drawTriangle();*/
			break;
		case(3):
			/*drawSquare();*/
			break;
		case(4):
			/*drawCircle();*/
			break;
		case(5):
			/*drawEliptic();*/
			break;
		default:
			; //NOP
	}
	glPopMatrix();
	glFlush();
	glutSwapBuffers();
}
/*
 * Menu Structure - Skeleton
 *
 *
*/
void menuSkeleton(int Item){
	if(Item!=0){
		menuOption=Item;
		printf("Selected: %d\n",Item);
	}
	else{
		menuOption=0;
		printf("No option selected\n");
	}

	glutPostRedisplay();
}

/*
 * Menu Structure - Creation
 *
 *
*/

void menuCreation(){
	int menid=glutCreateMenu(menuSkeleton);
	glutAddMenuEntry("Linha",1);
	glutAddMenuEntry("Triangulo",2);
	glutAddMenuEntry("Quadrado",3);
	glutAddMenuEntry("Circulo",4);
	glutAddMenuEntry("Elipse",5);

	glutAttachMenu(GLUT_RIGHT_BUTTON); 
}

void drawLine(){
	printf("Initial DOT: %d %d\n",x1,y1);
	printf("Final DOT: %d %d\n",x2,y2);


}

