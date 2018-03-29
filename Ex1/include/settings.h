#ifndef SETTINGS_H_
#define SETTINGS_H_
#define DEBUG     1
#define CONSOLE   1
// Macro for checking if debug is on
#define IF_DEBUG if(CONSOLE && DEBUG)

//define Viewport Size

#define SCREEN_SIZEX 1366
#define SCREEN_SIZEY 768
#define VIEWPORT_X 800
#define VIEWPORT_Y 600

#define ORTHO_X 300
#define ORTHO_Y 300
typedef  enum eMode{
	DRAW_LINE,
	DRAW_TRIANGLE,
	DRAW_SQUARE,
	DRAW_CIRCLE,
	DRAW_ELIPTIC,
	DRAW_IDLE
}eMode;

typedef struct DOT{
	int x, y;
}DOT;
#endif
