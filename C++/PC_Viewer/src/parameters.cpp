#include "parameters.h"

int w1, i, j, k, e;

int w0 = 650;
int h0 = 650;

int frame = 0;

// SACAR SCALE EN FUNCION DE LAS DIMENSIONES DEL MODELO
const double i_scale = 2000.;
double scale = i_scale;
double factor = 10;
double r_angle = 1.;

int mode, b_mode;

int pre_0, pre_1, pre_2;

int x_0, x_1, x_2;
int y_0, y_1, y_2;

double x_n, y_n;
double length;
		
double nx, ny;

double dx, dy;

GLfloat l_vector[4], g_vector[4];
GLfloat matrix[16], r_matrix[16];

vector<Point> nodes;
vector< vector<int> > tri;

vector<body> bodies;

double tx = 0., ty = 0., tz = 0.;