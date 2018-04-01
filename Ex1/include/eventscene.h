#ifndef EVENTSCENE_H_
#define EVENTSCENE_H_
#include "settings.h"
/*
 *
 * DOT init/set
 *
*/

void initDots();
void setDots();
/*
 *
 * display!
 *
*/
void display();
void reshape(int w, int h);
void cleanScreen();

/*
 *
 * draws!
 *
*/
void drawLine(DOT *p1, DOT *p2);
void drawTri(DOT *p1, DOT *p2);


/*
 *
 * Events goes here!
 *
*/


#endif
