/*
 *  scene1.h
 *  No Space
 *
 *  Created by Robert Nagtegaal on 2/1/10.
 *  Copyright 2010 __MyCompanyName__. All rights reserved.
 *
 */

/* OpenGL and SDL libs */
#include <GLUT/glut.h>
#include <OpenGL/gl.h>
#include <OpenGL/glu.h>

typedef double real;

class three_d {
public:
	real x, y, z; // 3d coordinates
	three_d() { x = y = z = 0; }
	three_d(real i, real j, real k) { x = i; y = j; z = k; }
	
	three_d operator+(three_d op2); // op1 is implied 
	three_d operator-(three_d op2); // op1 is implied
	three_d operator*(three_d op2); // op1 is implied
	three_d operator/(three_d op2); // op1 is implied
	three_d operator=(three_d op2); // op1 is implied
	real length_2(); // sqrt(x^2+y^2+z^2)
	void show();			
};

class DNFractal {
public:
	real multiplicationtable[3][6];
	DNFractal();
	DNFractal(real x[][6]);
	three_d iterate(three_d vector1, three_d vector2);
	bool is_in_fractal(three_d vector, int iterations, int threshold);
	
	
private:
	real f(three_d vector1, real mult[]) {
		return	mult[0] * vector1.x * vector1.x + mult[1] * vector1.x * vector1.y + 
		mult[2] * vector1.x * vector1.z + mult[3] * vector1.y * vector1.y +
		mult[4] * vector1.y * vector1.z + mult[5] * vector1.z * vector1.z;
	}
};

void mainloop();
void scene1();