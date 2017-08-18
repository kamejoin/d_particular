#include "mouse_action.h"
#include <math.h>
#include <iostream>

using namespace std;

mouse::mouse(void) { cout << "Mouse activated." << endl; }

void mouse::onMouseButton(int button, int state, int x, int y) {
	if (button == 0 && state == 0) { // Left Click - Pushed
		pre_0 = 1;
		x_0 = x; 
		y_0 = y;
	}
	if (button == 0 && state == 1) { // Left Click - Released
		pre_0 = 0;
	}

	if (button == 1 && state == 0) { // Middle Click - Pushed
		pre_1 = 1;
		x_1 = x;
		y_1 = y;
	}
	if (button == 1 && state == 1) { // Middle Click - Released
		pre_1 = 0;
	}

	if (button == 2 && state == 1) { // Right Click
		cout << "jola jola" << endl;
	}

	if (button == 3 && state == 1) { // Wheel Up
		scale += factor;
		glutPostRedisplay();
	}
	if (button == 4 && state == 1) { // Wheel Down
		scale -= factor;
		glutPostRedisplay();
	}
}

void mouse::mPosActive(int x, int y) {
	if (pre_0 == 1) {
		// Normalizacion
		length = sqrt((double)(x - x_0)*(x - x_0) + 
					  (double)(y_0 - y)*(y_0 - y));
		x_n = (x - x_0) / length;
		y_n = (y_0 - y) / length;

		// Normal vector
		if (y_n < 0) nx = 1.0;
		else nx = -1.0;
		if (y_n != 0) ny = - (x_n * nx) / y_n;

		// Global Coords
		global_vector(nx, ny);

		glMatrixMode(GL_MODELVIEW);
		glRotated(r_angle,g_vector[0],g_vector[1],g_vector[2]);
		
		glutPostRedisplay();
	}

	if (pre_1 == 1) {
		
		// Translation magnitude
	    dx = x - x_1;
	    dy = y - y_1;

	    x_1 = x;
	    y_1 = y;

		// HACER LA TRASLACION TOMANDO EN CUENTA LA ROTACION DEL MODELO
		global_vector(dx * 2. / w0, dy * 2. / h0);

	    tx += g_vector[0];
	    ty -= g_vector[1];
	    tz -= g_vector[2];

    	glutPostRedisplay(); 
	}
}

void mouse::mPosPassive(int x, int y) {
	int a = 1;
}
