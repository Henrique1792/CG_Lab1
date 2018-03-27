#ifndef MOUSE_H_
#define MOUSE_H_
#include "default.h"
//Mouse Directives

void mouseFreeMove(GLint x, GLint y);
void mouseDragMove(GLint x, GLint y);
void mouseClickAction(GLint button,GLint action, GLint x, GLint y);

#endif
