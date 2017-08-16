#include <GL/glut.h> 

// Initial size of window.
extern int w0;
extern int h0;
// zoom and change factor.
extern double i_scale;
extern double scale;
extern double factor;
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
// Plots mode
extern int mode;
extern int nei_mode;