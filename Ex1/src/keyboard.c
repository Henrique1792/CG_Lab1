#include "../include/keyboard.h"
#include "../include/transforms.h"



void proccessKey(unsigned char key, int x, int y){
	if(objectDraw){
		switch(key){
			case('+'):
			case('-'):
				if(currentMode==drawLINE)
					scaleLine(key);
				break;
		}
	}
}
void proccessSpecKey(int key, int x, int y){
	switch(key){
		case(GLUT_KEY_LEFT):
		case(GLUT_KEY_RIGHT):
			if(currentMode==drawLINE)
				rotateLine(key);
			break;
	}
}
