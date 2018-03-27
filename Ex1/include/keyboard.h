#ifndef KEYBOARD_H_
#define KEYBOARD_H_
#include "default.h"

void regkeyPressed(GLubyte key, GLint x, GLint y);
void specKeyPressed(GLint key, GLint x, GLint y);
void keyUp(GLint key, GLint x, GLint y);

#endif
