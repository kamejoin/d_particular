#include <GL/glut.h>
#include <stdio.h>
#include <math.h>
#include "parameters.h"

#define PI 3.14159265


GLfloat* traspose(GLfloat m[]);

GLfloat* mult_matrices(GLfloat m1[], GLfloat m2[], char r);

void save_matrix(GLfloat m1[], GLfloat m2[]);

void global_vector(double x, double y);

//void get_rotation();

void print_matrix(GLfloat m[]);
 

