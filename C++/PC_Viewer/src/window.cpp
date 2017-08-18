#include "window.h"

viewport vp;

window::window(void) { 

	glutInitWindowSize(w0, h0);
  	glutInitWindowPosition(100, 100);
  	w_id = glutCreateWindow("Cloud Surface Viewer");

	cout << "Window activated." << endl;
}

void reshape(int w, int h) {

	vp.x = 0;
  	vp.y = 0;
  	vp.w = w;
  	vp.h = h;

  	glViewport(vp.x, vp.y, vp.w, vp.h);
  	glMatrixMode(GL_PROJECTION);
  	glLoadIdentity();
   	gluOrtho2D((GLdouble) -w / (double)w0, (GLdouble) w / (double)w0, 
  			(GLdouble) -h / (double)h0, (GLdouble) h / (double)h0);
}


void reset_view() {
	// Reset View
	glViewport(vp.x, vp.y, vp.w, vp.h);
	gluOrtho2D((GLdouble) -vp.w / (double)w0, (GLdouble) vp.w / (double)w0, 
  				(GLdouble) -vp.h / (double)h0, (GLdouble) vp.h / (double)h0);
}
