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
#include "src/matrix_functions.h"
#include "src/mouse_action.h"
#include "src/keyboard_action.h"

using namespace std;

double rnd() {return double(rand()) / RAND_MAX;}

// General Parameters
int w1, i, j, k, e;
struct viewport {
	int x;
	int y;
	GLsizei w;
	GLsizei h;
};
viewport vp;

// Mouse Parameters
int px, py, pz, pos_x, pos_y, pos_z, pos_x2, pos_y2, pos_z2;
int mov_x, mov_y, mov_z;

// Relative Position Parameters
struct Axis { double x, y, z;};

// Rotation matrices & vectors
GLfloat* t_matrix, m_matrix;

// Mesh Info
vector<Point> nodes;
vector< vector<int> > tri, nei;


void init(void) {
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glShadeModel(GL_FLAT);
}

void mPosPassive(int x, int y) {
	pos_x = x;
	pos_y = y;
}

void reshape(int w, int h) {
	cout << w << " - " << h << endl;
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

void draw_axis() {
	// Corner View
	glViewport(0, 0, 150, 150);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0.0,0.0,1.0,1.0,-1.0,1.0);

	glLineWidth(2.0f);
	glBegin(GL_LINES);
	// x-axis
	glColor3f(1.0, 0.0, 0.0);
	glVertex3f(0.,0.,0.);
	glVertex3f(1.,0.,0.);
	// y-axis
	glColor3f(0.0, 1.0, 0.0);
	glVertex3f(0.,0.,0.);
	glVertex3f(0., 1., 0.);
	// z-axis
	glColor3f(0.0, 0.0, 1.0);
	glVertex3f(0.,0.,0.);
	glVertex3f(0.,0.,1.);
	glEnd();

	glColor3f(1.0, 1.0, 1.0);
	glRasterPos3f(1.,0.,0.);
	glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12,'x');
	glRasterPos3f(0., 1., 0.);
	glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12,'y');
	glRasterPos3f(0.,0.,1.);
	glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12,'z');

	// Reset View

	glViewport(vp.x, vp.y, vp.w, vp.h);
	gluOrtho2D((GLdouble) -vp.w / (double)w0, (GLdouble) vp.w / (double)w0, 
  				(GLdouble) -vp.h / (double)h0, (GLdouble) vp.h / (double)h0);
}

void display()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1.0, 1.0, 1.0);

	if (nei_mode == 0) {
		if (mode == 0) {
			glBegin(GL_POINTS);
			for(i=0; i<nodes.size(); i++) {
				glVertex3f(nodes[i].x / scale, 
							nodes[i].y / scale, 
							nodes[i].z / scale);
			} 
			glEnd();
		} else {
			glBegin(GL_TRIANGLES);
			for(i=1; i<tri.size(); i++) {
				for (j=0; j<3; j++) {
					glVertex3f(nodes[tri[i][j]].x / scale, 
								nodes[tri[i][j]].y / scale, 
								nodes[tri[i][j]].z / scale);
				}
			} 
			glEnd();
		}
	} else {
		if (mode == 0) glBegin(GL_POINTS);
		else glBegin(GL_TRIANGLES);

		for(i=1; i<tri.size(); i++) {
			if (nei[i].size() == nei_mode) {
				for (j=0; j<3; j++) {
					glVertex3f(nodes[tri[i][j]].x / scale, 
								nodes[tri[i][j]].y / scale, 
								nodes[tri[i][j]].z / scale);
				}
			}
		}
		glEnd(); 
	}
	draw_axis();
	glFlush();
}



int main(int argc, char** argv) {

	readmesh mesh("../../kj/botadero_centered.jh");
	nodes = mesh.nodes;
	tri = mesh.triangles;
	nei = mesh.neighbors;

	mouse m;
	keyboard k;
	
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
  	glutInitWindowSize(w0, h0);
  	glutInitWindowPosition(100, 100);
  	w1 = glutCreateWindow("Cloud Surface Viewer");
	init();
	
	glutPassiveMotionFunc(mPosPassive);
	glutMotionFunc(m.mPosActive);
	glutMouseFunc(m.onMouseButton);
	glutKeyboardFunc(k.keyboardAction);
	
	glutDisplayFunc(display);
	glutReshapeFunc(reshape);
	glutMainLoop();
	
	return 0;
}