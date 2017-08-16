#include <iostream>
#include "parameters.h"
#include "matrix_functions.h"
#include <GL/glut.h>

using namespace std;

class keyboard {
	public:
		keyboard();
		static void keyboardAction(unsigned char key, int x, int y);
};


