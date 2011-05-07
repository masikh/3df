#include <iostream>
#include <math.h>

using namespace std;

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


int main() {
	three_d	a(1, 0, 0), b(4, 5, 6), c(0.1,0.2,0.3), d, e, f;
	
	DNFractal iets=DNFractal();
	
	f = iets.iterate(a, b);
	cout << iets.is_in_fractal(b, 10, 25) << " is in fract\n";
	cout << iets.is_in_fractal(c, 10, 25) << " is in fract\n";	
/*	
	c = b - a;
	d = a * b;
	e = a / b;
	
	a.show();
	b.show();
	c.show();
	d.show();
	e.show();
	f.show();
*/	
	real size = 2.0;
	real step = 0.03;
	three_d temp;
	int count = 0;
	
	for (real i = -size; i < size; i += step) {
		for (real j = -size; j < size; j += step) {
			for (real k = -size; k < size; k += step) {
				temp = three_d(i, j, k);
				if (iets.is_in_fractal(temp, 100, 25)){count++;}
					//temp.show();
			}
		}
	}
	cout << count << endl;
	return(0);
}
