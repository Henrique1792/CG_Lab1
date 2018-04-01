#include "../include/mouse.h"



void menuSkeleton(int itemValue){
	if(itemValue>0)
		printf("selected: %d\n",itemValue);
	glutPostRedisplay();
}
void rMenu(){
	int menuId = glutCreateMenu(menuSkeleton);
	glutAddMenuEntry("Linha",1);
	glutAddMenuEntry("Triangulo",2);
	glutAddMenuEntry("Quadrado",3);
	glutAddMenuEntry("Circulo",4);
	glutAddMenuEntry("Elipse",5);

	glutAttachMenu(GLUT_RIGHT_BUTTON);
}

void onClick(int bt, int state, int x, int y){
	xMouse=x, yMouse=y, sMouse=state, bMouse=bt;
	dragging=(sMouse==GLUT_DOWN);
	switch(currentMode){
		case(drawLINE):
		case(drawTRI):
			if(bt==GLUT_LEFT_BUTTON && sMouse==GLUT_DOWN){
					p1->x=xMouse, p1->y=VIEWPORT_Y-yMouse;
					printf("Click: %d, %d\n", p1->x, p1->y);
			}
			break;
		case(drawIDLE):
			break;
	}
	glutPostRedisplay();

}

void onDrag(int x, int y){
	int oldX=xMouse, oldY=yMouse;
	switch(currentMode){
		case(drawLINE):
		case(drawTRI):
			if(bMouse==GLUT_LEFT_BUTTON && dragging){
					p2->x=x-oldX, p2->y=VIEWPORT_Y-y-oldY;
					lockLine=1;
					lockTri=1;
			}
			break;
			
	}
	glutPostRedisplay();
}
