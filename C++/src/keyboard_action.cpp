#include "keyboard_action.h"
#include <iostream>

using namespace std;

keyboard::keyboard(void) { cout << "Keyboard activated." << endl; }

void keyboard::keyboardAction(unsigned char key, int x, int y) {
	switch(key) {

		case 'i':
			// Initial position
			nei_mode = 0;
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

		case 'n':
			// Plot triangles as functions of their neighbors
			nei_mode++;
			if (nei_mode == 4) {nei_mode = 0;}
			cout << "Neighbors mode " << nei_mode << endl;
			glutPostRedisplay();

		case 't':
			if (mode == 0) {
				cout << "Facets mode" << endl;
				mode++;
			} else {
				cout << "Nodes mode" << endl;
				mode--;
			}
			glutPostRedisplay();
	}	
}