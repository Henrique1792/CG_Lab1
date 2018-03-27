#include "../include/default.h"
#include "../include/mouse.h"
#include "../include/keyboard.h"
#include "../include/drawing.h"
/*
 * Henrique F. M. Freitas - 8937225.
 * Ex: Set DDR algorithm for creating lines,circles,elipses and triangles using dots.
 *
 * Rotations, translations just permitted with Matrix Operations
 *
 * */


/*
 *
 * global variables
 *
 *
 */
//window
static GLint WINDOW_WIDTH=600,
        WINDOW_HEIGHT=600;
//Menu
int menuValue=0;

//Mouse positionx, position y, state
GLint xMouse, yMouse, sMouse, bt;
DOT p1, p2;
//Starting up Directives

/*
 * Submenu construction
 *
 * */
void faceMenu(GLint itemNumber){

	menuValue=itemNumber;
        glutPostRedisplay();
}
void rMenu(){
	GLint id=glutCreateMenu(faceMenu);
	glutAddMenuEntry("Linha", 1);
	glutAddMenuEntry("Triangulo", 2);
	glutAddMenuEntry("Circulo", 3);
	glutAddMenuEntry("Elipse", 4);

	glutAttachMenu(GLUT_RIGHT_BUTTON);
}

void init(){
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowSize(WINDOW_WIDTH,WINDOW_HEIGHT);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity(); //Load Identity matrix to reset drawing locations
	gluOrtho2D(0, WINDOW_WIDTH, 0, WINDOW_HEIGHT);
	rMenu();
}

int main(int argc, char *argv[]){
	GLint screen_width, screen_height;
	glutInit(&argc, argv);
	screen_width  = glutGet(GLUT_SCREEN_WIDTH),
	screen_height = glutGet(GLUT_SCREEN_HEIGHT);  
	glutInitWindowPosition((screen_width - WINDOW_WIDTH)/2, (screen_height - WINDOW_HEIGHT)/2);
	glutCreateWindow("Ex1");

	init();

	//Setting display
	glutDisplayFunc(display);
	//Setting keyboard events
	glutKeyboardFunc(regkeyPressed);
	glutSpecialFunc(specKeyPressed);

	//Setting mouse events
	glutMouseFunc(mouseClickAction);
	//Setting right click menu

	//Main Loop
	glutMainLoop();

	return EXIT_SUCCESS;
}
