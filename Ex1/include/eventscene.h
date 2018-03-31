#ifndef EVENTSCENE_H_
#define EVENTSCENE_H_
#include "settings.h"

/*
 *
 * display!
 *
*/
void display();

/*
 *
 * draws!
 *
*/
void drawLine(DOT *p1, DOT *p2);


/*
 *
 * Events goes here!
 *
*/

void onClick(int bt, int state, int x, int y);

#endif
