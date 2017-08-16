#include <GL/glut.h> 
#include "parameters.h"
#include "matrix_functions.h"

class mouse {
	public:
		// Constructor
		mouse();
		// Mouse click response
		static void onMouseButton(int button, int state, int x, int y);
		// Mouse click hold response
		static void mPosActive(int x, int y);
};


