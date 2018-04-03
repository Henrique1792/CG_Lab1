#include "../include/transforms.h"

/*************LINE**************/
void scaleLine(unsigned char key){
	if(key=='+'){
		if(p1->x > p2->x)
			p2->x--, p1->x++;
		else
			p1->x--, p2->x++;
		if(p1->y > p2->y)
			p1->y++, p2->y--;
		else
			p2->y++, p1->y--;
	}else{
		if(key=='-'){
			if(p1->x > p2->x)
				p2->x++, p1->x--;
			else
				p1->x++, p2->x--;
			if(p1->y > p2->y)
				p1->y--, p2->y++;
			else
				p2->y--, p1->y++;
		}
	}
	glutPostRedisplay();
}


void rotateLine(int key){
	float theta=(3*M_PI)/180;
	switch(key){
		case(GLUT_KEY_LEFT):
			p1->x=(cos(theta)*(p1->x))-(sin(theta)*(p1->y));
			p1->y=(sin(theta)*(p1->x))+(cos(theta)*(p1->y));
			break;
		case(GLUT_KEY_RIGHT):
			theta=-theta;
			p1->x=(cos(theta)*(p1->x))+(sin(theta)*(p1->y));
			p1->y=(sin(theta)*(p1->x))-(cos(theta)*(p1->y));
			break;
	}
	glutPostRedisplay();
}