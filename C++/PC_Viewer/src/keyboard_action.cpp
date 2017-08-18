#include "keyboard_action.h"
#include <iostream>

using namespace std;

keyboard::keyboard(void) { cout << "Keyboard activated." << endl; }

void keyboard::keyboardAction(unsigned char key, int x, int y) {
	switch(key) {

		case 'i':
			// Initial position
			tx = 0.; ty = 0.;
			scale = i_scale;
			glMatrixMode(GL_MODELVIEW);
			glLoadIdentity();
			glutPostRedisplay();
			break;

		case 'm':
			// Prints current matrix
			glGetFloatv(GL_MODELVIEW_MATRIX, matrix);
			print_matrix(matrix);
			break;

		case 'r':
			// Prints current rotation matrix
			print_matrix(r_matrix);
			break;


		case 't':
			if (mode == 0) {
				mode = 1;
				cout << "Facets mode" << endl;
			}
			else {
				mode = 0;
				cout << "Nodes mode" << endl;
			}
			glutPostRedisplay();
			break;


		case 'b':
			if (b_mode == 0) {
				b_mode = 1;
				cout << "Bodies displayed" << endl;
			}
			else {
				b_mode = 0;
				cout << "Bodies hidden" << endl;
			}
			glutPostRedisplay();
			break;
	}
}