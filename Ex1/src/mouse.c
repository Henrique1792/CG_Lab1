#include "../include/mouse.h" 

/*************Menus**************/ 
void menuShape(int itemValue){
	switch(itemValue){
		case(drawLINE):
		case(drawTRI):
		case(drawSQR):
		case(drawCIR):
		case(drawELI):
			printf("selected: %d\n",itemValue);
			currentMode=itemValue;
		break;
	}
	glutPostRedisplay();
}

void menuMain(int itemValue){
	printf("SubMenu: %d\n", itemValue);
}
void rMenu(){
	int menuS = glutCreateMenu(menuShape);
	glutAddMenuEntry("Linha",1);
	glutAddMenuEntry("Triangulo",2);
	glutAddMenuEntry("Quadrado",3);
	glutAddMenuEntry("Circulo",4);
	glutAddMenuEntry("Elipse",5);

	int mainMenu=glutCreateMenu(menuMain);
	glutAddSubMenu("Shape",menuS);
	glutAttachMenu(GLUT_RIGHT_BUTTON);
}

/*************onClick Event**************/ 
void onClick(int bt, int state, int x, int y){
	xMouse=x, yMouse=y, sMouse=state, bMouse=bt;
	dragging=(sMouse==GLUT_DOWN);
	switch(currentMode){
		case(drawLINE):
			if(bt==GLUT_LEFT_BUTTON && sMouse==GLUT_DOWN){
					p1->x=xMouse, p1->y=VIEWPORT_Y-yMouse;
					printf("Click: %d, %d\n", p1->x, p1->y);
			}
			if(currentTransform==TRL){
				
				
			}
			break;
		case(drawTRI):
			if(bt==GLUT_LEFT_BUTTON && sMouse==GLUT_DOWN){
					p1->x=xMouse, p1->y=VIEWPORT_Y-yMouse;
					printf("Click: %d, %d\n", p1->x, p1->y);
			}
			break;
		case(drawSQR):
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

/*************onDrag Event**************/ 
void onDrag(int x, int y){
	int oldX=xMouse, oldY=yMouse;
	switch(currentMode){
		case(drawLINE):
		case(drawTRI):
		case(drawSQR):
			if(bMouse==GLUT_LEFT_BUTTON && dragging){
					p2->x=x-oldX, p2->y=VIEWPORT_Y-y-oldY;
					if(currentMode==drawLINE)
						lockLine=1;
					if(currentMode==drawTRI)
						lockTri=1;
					if(currentMode==drawSQR)
						lockSqr=1;
			}
			break;
			
	}
	glutPostRedisplay();
}
