#include <GL/glut.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "../include/scene.h"
#include "../include/events.h"
#include "../include/settings.h"


/*global variables
 * menuOption: option enabled on menu
 * xMouse, yMouse: Last position of pointer
 *
*/

int menuOption=0;
int xMouse, yMouse, sMouse;
eMode currentMode=DRAW_IDLE;
DOT *p1, *p2;
//init function

void init(){
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowSize(VIEWPORT_X, VIEWPORT_Y);
	glutInitWindowPosition((SCREEN_SIZEX-VIEWPORT_X)/2, (SCREEN_SIZEY-VIEWPORT_Y)/2);
	glutCreateWindow("Ex1"); 
	menuCreation();
}

int main(int argc, char *argv){
	IF_DEBUG{
		printf("Initializing...\n");
		printf("Window: Ex1\n");
	}
	//set init window
	glutInit(&argc, &argv);
	init();
	IF_DEBUG printf("Window Created\n");
	
	//set callbacks
	//drawing
		glutDisplayFunc(drawLoop);
	IF_DEBUG printf("Draw callback set\n");
		
		//mouseClick
		glutMouseFunc(onClick);
		 
	IF_DEBUG printf("Mouse callback set\n");

		//keyboard
		/*glutKeyboardFunc(keyPressed);*/
	/*IF_DEBUG printf("Keyboard callback set\n");*/

		//set Matrix Mode
		glMatrixMode(GL_VIEWPORT);
		glViewport(0,0,VIEWPORT_X,VIEWPORT_Y);
		gluOrtho2D(-ORTHO_X,ORTHO_X,-ORTHO_Y,ORTHO_Y);

		IF_DEBUG printf("matrix viewport set up\n");
		glMatrixMode(GL_MODELVIEW);
		
		initDots();
		glutMainLoop();
		freeDots();
	return 0;

}
