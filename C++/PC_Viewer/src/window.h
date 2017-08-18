#ifndef WIN_H
#define WIN_H

#include <GL/glut.h>
#include <iostream>
#include "parameters.h"

struct viewport {
	int x;
	int y;
	GLsizei w;
	GLsizei h;
};

extern viewport vp;

class window {
	public:
		window();
		int w_id;

};

void reshape(int w, int h);
void reset_view();

#endif