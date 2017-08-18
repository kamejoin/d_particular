#include "drawings.h"
#include <iostream>

void draw_model() {

	glClear(GL_COLOR_BUFFER_BIT);

	if (mode == 0) {
		glColor3f(1.0, 1.0, 1.0);
		glBegin(GL_POINTS);
		for(i=0; i<nodes.size(); i++) {
			glVertex3f(nodes[i].x / scale + tx, 
						nodes[i].y / scale + ty, 
						nodes[i].z / scale + tz);
		} 
		glEnd();
	} else {

		glColor3f(1.0, 1.0, 1.0);
		glPolygonMode(GL_FRONT_AND_BACK,GL_LINE);
		glLineWidth(0.5f);
		glBegin(GL_TRIANGLES);
		for(i=0; i< tri.size(); i++) {
			for (j=0; j<3; j++) {
				glVertex3f(nodes[tri[i][j]].x / scale + tx, 
							nodes[tri[i][j]].y / scale + ty, 
							nodes[tri[i][j]].z / scale + tz);
			}
		}
		glEnd();
	}
}

void draw_body() {
	for (i=0;i<bodies.size();i++) {
		glColor3f(bodies[i].color.r, bodies[i].color.g, bodies[i].color.b);

		if (mode == 0) {
			glBegin(GL_POINTS);
			for(j=0; j<bodies[i].nodes.size(); j++) {
				glVertex3f(bodies[i].nodes[j].x / scale + tx, 
							bodies[i].nodes[j].y / scale + ty, 
							bodies[i].nodes[j].z / scale);
			} 
			glEnd();
		} else {
			glPolygonMode(GL_FRONT_AND_BACK,GL_LINE);
			glLineWidth(0.5f);
			glBegin(GL_TRIANGLES);
			for(j=0; j< bodies[i].triangles.size(); j++) {
				for (k=0; k<3; k++) {
					glVertex3f(bodies[i].nodes[bodies[i].triangles[j][k]].x / scale + tx, 
								bodies[i].nodes[bodies[i].triangles[j][k]].y / scale + ty, 
								bodies[i].nodes[bodies[i].triangles[j][k]].z / scale);
				}
			}
			glEnd();
		}
	}
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

}

void draw_all() {

	draw_model();
	if (b_mode == 1) draw_body();
	draw_axis();
	glFlush();
	reset_view();
	
}