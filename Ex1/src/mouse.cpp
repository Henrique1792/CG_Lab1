#include "../include/mouse.h"

int extern menuValue;
GLint extern xMouse, yMouse, sMouse, bt;
DOT extern p1, p2;

void mouseFreeMove(GLint x, GLint y){
	xMouse=x, xMouse=y;
}
void mouseDragMove(GLint x, GLint y);

void mouseClickAction(GLint button,GLint action, GLint x, GLint y){
	bt=button, sMouse=action, xMouse=x,yMouse=y;
	switch(menuValue){
	case(1):
		if(button==GLUT_LEFT_BUTTON && action==GLUT_DOWN){
			std::cout << "Iline x: "<<x<< "Iline y: "<<y<<"";
			p1.x=x;
			p1.y=y;
		}else if(button==GLUT_LEFT_BUTTON && action==GLUT_UP){
			std::cout << "Fline x: "<<x<< "Fline y: "<<y<<"";
			p2.x=x;
			p2.y=600-y;
		}
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
		if(bt==GLUT_RIGHT_BUTTON)
			std::cout << "Create submenu on right click\n";
	}
}
