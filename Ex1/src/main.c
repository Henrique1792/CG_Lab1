#include "../include/settings.h"
#include "../include/eventscene.h"
#include "../include/mouse.h"

DOT extern *p1, *p2;
dMode extern currentMode;



void initDots(){
	p1=(DOT *)malloc(sizeof(DOT));
	p2=(DOT *)malloc(sizeof(DOT));
	
}

void setDots(){
	p1->x=0, p1->y=0;
	p2->x=0, p2->y=0;
}
void freeDots(){
	free(p1);
	free(p2);
}
void init(){

	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowSize(VIEWPORT_X, VIEWPORT_Y);
	glutInitWindowPosition((SCREEN_SIZEX-VIEWPORT_X)/2, (SCREEN_SIZEY-VIEWPORT_Y)/2);
	glutCreateWindow("Ex1");

	glMatrixMode(GL_PROJECTION);
	glViewport(0,0,VIEWPORT_X,VIEWPORT_Y);
	glLoadIdentity();
	gluOrtho2D(0,VIEWPORT_X, 0,VIEWPORT_Y);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	rMenu();

}


int main(int argc, char *argv[]){
	initDots();
	lockLine=0;
	currentMode=drawLINE;
	glutInit(&argc, argv);
	init();
	printf("Window Created\n");
	glutDisplayFunc(display);
	
	glutMouseFunc(onClick);
	glutMotionFunc(onDrag);
	glutMainLoop();
	freeDots();
}
