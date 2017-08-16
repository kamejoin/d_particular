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

 
GLfloat* mult(GLfloat m1[], GLfloat m2[]) {
	static GLfloat m_matrix[16];
	double sum=0.;
	for (int i=0; i<4; i++) {
		for(int j=0; j<4; j++) {
			sum = 0.;
			for(int k=0; k<4; k++) {
				sum += m1[4*i + k] * m2[4*k + j];
			}
			if (sum <= 1.e-4) sum = 0.;
			if (sum + 1e-3 >= 1.) sum = 1.;
			m_matrix[4*i + j] = sum;
		}
	}
	return m_matrix;
}

void global_vector() {
	glGetFloatv(GL_MODELVIEW_MATRIX, matrix);
	// Local vector
	l_vector[0] = nx;
	l_vector[1] = ny;
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