#include <cstdlib>
#include <iostream>
#include <GL/glut.h>

//Global Variables

GLint WINDOW_WIDTH=600,
        WINDOW_HEIGHT=600;

void init();
void draw_test();


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
