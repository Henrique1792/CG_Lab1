#include <cstdlib>
#include <iostream>
#include <GL/glut.h>

/*
 * Henrique F. M. Freitas - 8937225.
 * Ex: Set DDR algorithm for creating lines using dots.
 *
 * Rotations, translations just permitted with Matrix Operations
 *
 * */



//Global Variables

GLint WINDOW_WIDTH=600,
        WINDOW_HEIGHT=600;

//Starting up Directives
void init();
void display();

//Mouse Directives
void mouseFreeMove(GLint x, GLint y);
void mouseDragMove(GLint x, GLint y);
void mouseClickAction(GLint button,GLint action, GLint x, GLint y);

//Keyboard Directives
void regkeyPressed(GLubyte key, GLint x, GLint y);
void specKeyPressed(GLint key, GLint x, GLint y);
void keyUp(GLint key, GLint x, GLint y);

//Menu Directives
void rightClickMenu_Content(GLint item_number);
void rightClickMenu();

int main(int argc, char *argv[]){
        //Setting Window
        glutInit(&argc, argv);
        glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
        glutInitWindowSize(WINDOW_WIDTH,WINDOW_HEIGHT);
        glutInitWindowPosition(WINDOW_WIDTH/2, WINDOW_HEIGHT/2);
        glutCreateWindow("Ex1");
        
        //Setting display
        glutDisplayFunc(display);
        glutKeyboardFunc(regkeyPressed);
        glutSpecialFunc(specKeyPressed);


        glutMainLoop();



        return EXIT_SUCCESS;
}
/*
 * Function to display screen
 *
 * */

void display(){
        glClearColor(0.0, 0.0, 0.0, 0.0); // set background color
        glClear(GL_COLOR_BUFFER_BIT); //reset color buffer
        glLoadIdentity(); //Load Identity matrix to reset drawing locations

        glFlush(); 
}

/*
 * Keyboard Functions
 *
 * regkeyPressed deals with regualar keys
 * specKeyPressed deals with special keys (arrows, in our case)
 * */
void regkeyPressed(GLubyte key, GLint x, GLint y){
        switch(key){
        case GLint('+'):
                std::cout << "Scale Line\n";
                break;
        case GLint('-'):
                std::cout << "Scale line - \n";
                break;
       }
}
void specKeyPressed(GLint key, GLint x, GLint y){
        switch(key){
        case GLUT_LEFT_BUTTON:
                std::cout << "5 degress counter-clockwise Rotation\n";
                break;
        case GLUT_RIGHT_BUTTON:
                std::cout << "5 degress clockwise Rotation\n";
                break;
        }



}

void mouseClickAction(GLint button,GLint action, GLint x, GLint y){
        if(action == GLUT_DOWN && action==GLUT_LEFT_BUTTON){
                //draw dot at x,y 
        }

        if(action == GLUT_DOWN && action==GLUT_RIGHT_BUTTON){
                //draw dot at x,y 
        }
}



