//#include <GL/gl.h>
//#include <GL/glu.h>
/* http://www.transmissionzero.co.uk/software/freeglut-devel/ "MinGW Package"
	check "makefile" and paste freeglut.dll into this directory. */
#include <GL/glut.h> 
#include <vector>
#include <math.h>
#include <stdlib.h> 

#include "src/parameters.h"
#include "src/read_mesh.h"
#include "src/window.h"
#include "src/drawings.h"
#include "src/matrix_functions.h"
#include "src/mouse_action.h"
#include "src/keyboard_action.h"

using namespace std;


void init(void) {
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glShadeModel(GL_FLAT);
}


void display()
{
	draw_all();
}


int main(int argc, char** argv) {

	readmesh mesh("../../kj/derk_centered_surf.kj");

	body botadero("../../kj/botadero_centered.kj", "r");
	bodies.push_back(botadero);

	cout << botadero.color.r << endl;

	nodes = mesh.nodes;
	tri = mesh.triangles;

	mouse m;
	keyboard k;

	glutInit(&argc, argv);
	window win;

	init();
	glutMotionFunc(m.mPosActive);
	glutMouseFunc(m.onMouseButton);
	glutPassiveMotionFunc(m.mPosPassive);
	glutKeyboardFunc(k.keyboardAction);
	glutDisplayFunc(display);
	glutReshapeFunc(reshape);
	glutMainLoop();
	
	return 0;
}