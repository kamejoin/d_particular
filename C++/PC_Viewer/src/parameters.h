#ifndef PAR_H
#define PAR_H

#include <GL/glut.h> 
#include <vector>
#include "read_mesh.h"

using namespace std;

// General Parameters
// Window int
extern int w1;
// Common use integers
extern int i;
extern int j;
extern int k;
extern int e;
// Initial size of window.
extern int w0;
extern int h0;
// Current frame
extern int frame;

// zoom, change factor, rotation default angle (degress).
const extern double i_scale;
extern double scale;
extern double factor;
extern double r_angle;
// Mode: 0: Nodes, 1: Triangles
extern int mode;
// b_mode: 0: NO, 1: YES
extern int b_mode;
// mouse buttons state.
extern int pre_0;
extern int pre_1;
extern int pre_2;
// Initial position of click swipe.
extern int x_0;
extern int x_1;
extern int x_2;
extern int y_0;
extern int y_1;
extern int y_2;
// Normalized vector of line drawn by swipe.
extern double x_n;
extern double y_n;
extern double length;
// Normal vector to line.
extern double nx;
extern double ny;
// Difference between coords
extern double dx;
extern double dy;
// Vector and matrix of viewer position.
extern GLfloat l_vector[4];
extern GLfloat g_vector[4];
extern GLfloat matrix[16];
// Rotation-only matrix
extern GLfloat r_matrix[16];

// Mesh Info
extern vector<Point> nodes;
extern vector< vector<int> > tri;

// Bodies
extern vector<body> bodies;

// Translation
extern double tx;
extern double ty;
extern double tz;


#endif