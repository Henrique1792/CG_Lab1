#include <cstdlib>
#include <iostream>
#include <GL/glut.h>

/*
 * Henrique F. M. Freitas - 8937225.
 * Ex: Set DDR algorithm for creating lines using dots.
 *
 *
 * */
//Global Variables

GLint WINDOW_WIDTH=600,
        WINDOW_HEIGHT=600;

//Starting up Directives
void init();
void draw_test();

//Mouse Directives
void mouseFreeMove(GLint x, GLint y);
void mouseDragMove(GLint x, GLint y);
void mouseClickAction(GLint button,GLint action, GLint x, GLint y);

//Keyboard Directives
void keyboardRegularKey(GLint key, GLint x, GLint y);
void keyboardSpecialKey(GLint key, GLint x, GLint y);

//Menu Directives
void rightClickMenu_Content(GLint item_number);
void rightClickMenu();

int main(int argc, char *argv[]){
        glutInit(&argc, argv);
        glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
        glutInitWindowSize(400,400);
        glutInitWindowPosition(WINDOW_WIDTH/2, WINDOW_HEIGHT/2);
        glutCreateWindow("Ex1");
        




        init();
        draw_test();
        glutMainLoop();



        return EXIT_SUCCESS;
}
