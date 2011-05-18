#include "scene1.h"
#include <cmath>
#include <iostream>
#include <math.h>

using namespace std;

// overload the + operator
three_d three_d::operator+(three_d op2) {
	three_d temp;
	
	temp.x = x + op2.x; 
	temp.y = y + op2.y;
	temp.z = z + op2.z;
	return temp;
}

// overload the - operator
three_d	three_d::operator-(three_d op2) {
	three_d temp;
	
	temp.x = x - op2.x;
	temp.y = y - op2.y;
	temp.z = z - op2.z;
	return temp;
}

// overload the * operator
three_d three_d::operator*(three_d op2) {
	three_d temp;
	
	temp.x = x * op2.x;
	temp.y = y * op2.y;
	temp.z = z * op2.z;
	return temp;
}

// overload the / operator
three_d three_d::operator/(three_d op2) {
	three_d temp;
	
	temp.x = x / op2.x;
	temp.y = y / op2.y;
	temp.z = z / op2.z;
	return temp;
}

// overload the = operator
three_d three_d::operator=(three_d op2) {
	x = op2.x;
	y = op2.y;
	z = op2.z;
	return *this;
}

// length_2 of point to origin
real three_d::length_2() {
	return x*x + y*y + z*z;
}

// Show some output
void three_d::show() {
	cout << "x: " << x << " y: " << y << " z: " << z << endl;
}	

bool DNFractal::is_in_fractal(three_d vector, int iterations, int threshold) {
	three_d vbegin(0, 0, 0);
	for (int i = 0; i < iterations; i++) {
		vbegin = iterate(vbegin, vector);
		if (vbegin.length_2() > 25)
			return false;
	}
	return true;
}

DNFractal::DNFractal(){
	for(int i=0; i<3;i++){
		for(int j=0; j<6; j++){
			multiplicationtable[i][j]=(real) 0.1 * ((real) i + j + 1);
		}
	}
}


DNFractal::DNFractal(real x[][6]){
	for(int i=0; i<3;i++){
		for(int j=0; j<6; j++){
			multiplicationtable[i][j]=x[i][j];
		}
	}
}

three_d DNFractal::iterate (three_d vector1, three_d vector2) {
	real x0, x1, x2;
	three_d temp;
	x0 = f(vector1, multiplicationtable[0]);
	x1 = f(vector1, multiplicationtable[1]);
	x2 = f(vector1, multiplicationtable[2]);
	
	temp = three_d(x0, x1, x2);
	return temp + vector2;
}

void mainloop() {
	three_d	a(1, 0, 0), b(4, 5, 6), c(0.1,0.2,0.3), d, e, f;
	
	DNFractal fractal=DNFractal();
	
	f = fractal.iterate(a, b);

	real size = 2.0;
	real step = 0.03;
	three_d temp;
	int count = 0;
	
	for (real i = -size; i < size; i += step) {
		for (real j = -size; j < size; j += step) {
			for (real k = -size; k < size; k += step) {
				temp = three_d(i, j, k);
				if (fractal.is_in_fractal(temp, 100, 25)){
                    count++;
					glVertex3f( temp.x, temp.y, temp.z);
                }// Move Up One Unit From Center (Top Point)
			}
		}
	}
}

void scene1() {
	glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );
	glPushMatrix();
	
	glBegin(GL_POINTS);					// Begin Drawing Triangles
	
		glColor3f(1.0f,0.0f,0.0f);			// Set The Color To Red
		mainloop();
	
	glEnd();			
		
	glPopMatrix();
	glutSwapBuffers();
}
