#include "../include/scene.h"

//Extern Variables

int extern menuOption;

/*
 * drawing
 *
*/
void drawLoop(){
	//Load background color and object color
	glClearColor(1.0,1.0,1.0,0.0);
	glColor3f(1.0,1.0,1.0);
	
        // Repaint screen
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	//Drawing Menu Options
	glPushMatrix();
	switch(menuOption){
		case(1):
			break;
		case(2):
			break;
		case(3):
			break;
		case(4):
			break;
		case(5):
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
	if(Item!=0)
		menuOption=Item;
	else{
		menuOption=0;
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


/*
 * Events - Mouse
 *
 *
*/
void onClick(int x, int y, int action, int button){
	switch(action){
		case(GLUT_DOWN):
			break;
	
	
	
	
	}

}
/*
 * Events - Keyboard
 *
 *
*/
void keyPressed(unsigned char key, int x, int y);
