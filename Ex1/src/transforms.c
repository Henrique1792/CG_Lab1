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
	int midX, midY, prevMidx, prevMidy;
	double theta=(4*M_PI)/180.f;

	prevMidx=midX=(p1->x+p2->x)/2;
	prevMidy=midY=(p1->y+p2->y)/2;
	int x1_aux, y1_aux;
	int x2_aux, y2_aux;
	//Translate midX, midY

	p1->x-=prevMidx;
	p1->y-=prevMidy;
	p2->x-=prevMidx;
	p2->y-=prevMidy;

	x1_aux=p1->x;
	x2_aux=p2->x;

	y1_aux=p1->y;
	y2_aux=p2->y;
	if(key==GLUT_KEY_RIGHT) theta=-theta;
	
	p1->x=(cos(theta)*(x1_aux))-(sin(theta)*(y1_aux));
	p2->x=(cos(theta)*(x2_aux))-(sin(theta)*(y2_aux));
	
	p1->y=(sin(theta)*(x1_aux))+(cos(theta)*(y1_aux));
	p2->y=(sin(theta)*(x2_aux))+(cos(theta)*(y2_aux));
	
	p1->x+=prevMidx;
	p1->y+=prevMidy;
	p2->x+=prevMidx;
	p2->y+=prevMidy;
	glutPostRedisplay();
}

void translateLine(int x, int y){
	int prevMidx, prevMidy,midX, midY;
	//Calculate midLine
	
	prevMidx=midX=abs(p1->x-p2->x)/2.0;
	prevMidy=midY=abs(p1->y-p2->y)/2.0;
	
	//Translate mid
	midX=x;
	midY=y;
	
	//Adjust p1 and p2
	
	if(p1->x > p2->x){
		p1->x=midX-prevMidx;
		p2->x=midX+prevMidx;
	}else{
		p1->x=midX+prevMidx;
		p2->x=midX-prevMidx;
	}

	if(p1->y > p2->y){
		p1->y=midY-prevMidy;
		p2->y=midY+prevMidy;
	}else{
		p1->y=midY+prevMidy;
		p2->y=midY-prevMidy;
	}
	glutPostRedisplay();
}
/*************TRIANGLE**************/