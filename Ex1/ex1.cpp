#include <cstdlib>
#include <cstring>
#include <iostream>
#include <GL/glut.h>

/*
 * Henrique F. M. Freitas - 8937225.
 * Ex: Set DDR algorithm for creating lines,circles,elipses and triangles using dots.
 *
 * Rotations, translations just permitted with Matrix Operations
 *
 * */



//Global Variables

GLint WINDOW_WIDTH=600,
        WINDOW_HEIGHT=600;

//Starting up Directives
void init(){
        glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
        glutInitWindowSize(WINDOW_WIDTH,WINDOW_HEIGHT);
        gluOrtho2D(0, WINDOW_WIDTH, 0, WINDOW_HEIGHT);
}
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
void rMenu();
void faceMenu(GLint itemNumber);

int main(int argc, char *argv[]){
        GLint screen_width, screen_height;
        glutInit(&argc, argv);
        init();
        screen_width  = glutGet(GLUT_SCREEN_WIDTH),
        screen_height = glutGet(GLUT_SCREEN_HEIGHT);  
        glutInitWindowPosition((screen_width - WINDOW_WIDTH)/2, (screen_height - WINDOW_HEIGHT)/2);
        glutCreateWindow("Ex1");
        
        //Setting display
        glutDisplayFunc(display);
        //Setting keyboard events
        glutKeyboardFunc(regkeyPressed);
        glutSpecialFunc(specKeyPressed);

        //Setting mouse events
        glutMouseFunc(mouseClickAction);
        //Setting right click menu
        rMenu();
        glutMainLoop();



        return EXIT_SUCCESS;
}
/*
 * Function to display screen
 *
 * */

void display(){
        glClearColor(1.0, 1.0, 1.0, 1.0); // set background color
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
        if(key==GLUT_KEY_LEFT)
                std::cout << "5 degress counter-clockwise Rotation\n";
        else{
                if(key==GLUT_KEY_RIGHT)
                std::cout << "5 degress clockwise Rotation\n";
        }
}

/*
 * mouse events deal
 * */
void mouseClickAction(GLint button,GLint action, GLint x, GLint y){
        switch(button){
                case GLUT_LEFT_BUTTON:
                        std::cout << "Translate drawing at "<<x<<" "<<y<<"\n";
                        break;
                case GLUT_RIGHT_BUTTON:
                        std::cout << "Create submenu on right click\n";
        }
}

/*
 * Submenu construction
 *
 * */
void faceMenu(GLint itemNumber){

        std::cout<<"Item "<<itemNumber<<" \n";
        glutPostRedisplay();
}
void drawString(char *s){
        unsigned int i;

        for(i=0;i<strlen(s);i++)
                glutBitmapCharacter (GLUT_BITMAP_HELVETICA_10, s[i]); 


}
void rMenu(){
        GLint id=glutCreateMenu(faceMenu);
        glutAddMenuEntry("Linha", 1);
        glutAddMenuEntry("Triângulo", 2);
        glutAddMenuEntry("Círculo", 3);
        glutAddMenuEntry("Elipse", 4);
        
        glutAttachMenu(GLUT_RIGHT_BUTTON);
}
