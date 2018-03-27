#include "../include/keyboard.h"

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
