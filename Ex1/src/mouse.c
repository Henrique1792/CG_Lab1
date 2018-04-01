#include "../include/mouse.h"




dMode extern currentMode;
void menuSkeleton(int itemValue){
	currentMode=itemValue;
	glutPostRedisplay();
}
void rMenu(){
	int menuId = glutCreateMenu(menuSkeleton);
	glutAddMenuEntry("Linha",1);
	glutAddMenuEntry("Triângulo",2);
	glutAddMenuEntry("Quadrado",3);
	glutAddMenuEntry("Círculo",4);
	glutAddMenuEntry("Elipse",5);

	glutAttachMenu(GLUT_RIGHT_BUTTON);
}

void onClick(int bt, int state, int x, int y){
	xMouse=x, yMouse=y, sMouse=state;
	if(bt==GLUT_LEFT_BUTTON && state==GLUT_DOWN){
		if(!lockP1){
			p1->x=xMouse, p1->y=VIEWPORT_Y-yMouse;
			lockP1=1;
		}
		else{
			p2->x=xMouse, p2->y=VIEWPORT_Y-yMouse;
			lockP1=0;
		}
	}
	glutPostRedisplay();
}
