#include "matrix_functions.h"

GLfloat* traspose(GLfloat m[]) {
	static GLfloat t_matrix[16];
	for (int i=0; i<4; i++) {
		for(int j=0; j<4; j++) {
			t_matrix[4*j + i] = m[4*i + j];
		}
	}
	return t_matrix;
}

 
GLfloat* mult_matrices(GLfloat m1[], GLfloat m2[], char r) {
	static GLfloat m_matrix[16];
	double sum=0.;
	for (int i=0; i<4; i++) {
		for(int j=0; j<4; j++) {
			sum = 0.;
			for(int k=0; k<4; k++) {
				sum += m1[4*i + k] * m2[4*k + j];
			}
			/*
			if (sum <= 1.e-5) sum = 0.;
			if (sum + 1e-4 >= 1.) sum = 1.;*/
			m_matrix[4*i + j] = sum;
		}
	}

	// Recursive, product saved on m2
	if (r == 'r') save_matrix(m_matrix, m2);

	return m_matrix;
}

void save_matrix(GLfloat m1[], GLfloat m2[]) {
	for (int i=0; i < 16; i++) m2[i] = m1[i];
}


void global_vector(double x, double y) {
	glGetFloatv(GL_MODELVIEW_MATRIX, matrix);
	// Local vector
	l_vector[0] = x;
	l_vector[1] = y;
	l_vector[2] = 0;
	l_vector[3] = 0;

	double sum=0.;
	for (int i=0; i<4; i++) {
		sum = 0.;
		for(int j=0; j<4; j++) {
			sum += matrix[4*i + j] * l_vector[j];
		}
		g_vector[i] = sum;
	}
}


void print_matrix(GLfloat m[]) {
	for (int i=0; i<4; i++) {
		for(int j=0; j<4; j++) {
			printf("%g ", m[4*i + j]);
		}
		puts("");
	}
	puts("");
}

/*
void get_rotation() {
	double N = g_vector[0] * g_vector[0] + g_vector[1] * g_vector[1] + g_vector[2] * g_vector[2];
	double ux = g_vector[0] /  N;
	double uy = g_vector[1] /  N;
	double uz = g_vector[2] /  N;

	GLfloat t_matrix[16]; // Transitory matrix

	double c = cos(r_angle * PI/180);
	double s = sin(r_angle * PI/180);

	t_matrix[0]  = c + ux * ux * (1 - c);
	t_matrix[1]  = ux * uy * (1 - c) - uz * s;
	t_matrix[2]  = ux * uz * (1 - c) + uy * s;
	t_matrix[3]  = 0.;
	t_matrix[4]  = ux * uy * (1 - c) + uz * s;
	t_matrix[5]  = c + uy * uy * (1 - c);
	t_matrix[6]  = uy * uz * (1 - c) - ux * s;
	t_matrix[7]  = 0.;
	t_matrix[8]  = ux * uz * (1 - c) - uy * s;
	t_matrix[9]  = uy * uz * (1 - c) + ux * s;
	t_matrix[10] = c + uz * uz * (1 - c);
	t_matrix[11] = 0.;
	t_matrix[12] = 0.;
	t_matrix[13] = 0.;
	t_matrix[14] = 0.;
	t_matrix[15] = 1.;

	mult_matrices(t_matrix, r_matrix, 'r');

}*/