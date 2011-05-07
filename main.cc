#include <iostream>
#include <math.h>
#include "./main.h"

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

// This function creates a new item
item::item() {
    this->next = NULL;						// New item with two NULL pointers and
    this->prev = NULL;						// two digits both set to 0 initially
    this->vector = three_d(0, 0, 0);		// The two pointers may be pointed to another
    this->iterations = 0;					// item object elsewhere
}

// This (overloaded) function creates a new item with content
item::item(three_d vector, int iterations) {// New item with two NULL pointers
    this->next = NULL;						// These pointers are created during execution of add() 
    this->prev = NULL;						// when a carry occurs in add(). 
    this->vector = vector;							// The carry (always 1) is stored in temp
    this->iterations = iterations;						// and the actual value of THIS item is digit
}

// Destructor: It removes an item from a list.
item::~item() {
    if (this->next)							// If pointer to next item exists (thus not NULL)
		delete this->next;					// then delete next item
}

// This function creates a new list
list::list() {
    this->begin = NULL;						// Set the pointers to the begin and end
    this->end = NULL;						// of the list to NULL
}

// Destructor: This function destroys a list
list::~list() {
    if (this->begin)						// If the pointer to begin in THIS list is not NULL
		delete begin;						// then delete pointer to begin.
}

// This function adds a new item to the begin of the doublelinked list.
void list::unshift(item * itemObj) {
    if (this->begin) {						// If the begin of the list is not NULL
		this->begin->prev = itemObj;		// point prev to new itemObj
		itemObj->next = this->begin;		// and next from itemObj to begin.
    }
    this->begin = itemObj;					// point begin to new itemObj
    if (!this->end)							// If end is NULL, then
		this->end = this->begin;			// end equals begin. (thus empty list)
}

// This function removes an item from the begin of a doublelinked list.
item *list::shift() {
    if (this->begin) {						// If a non-empty list exists,
		item *dummy = this->begin;			// set a dummy pointer to begin
		if (this->begin->next) {			// If there exists a next item
			this->begin = this->begin->next;// point begin to the next item
			this->begin->prev = NULL;		// and set the pointer prev to NULL
		} else {							// else we have reached the last element to destroy
			this->end = NULL;				// and must point both begin and end
			this->begin = NULL;				// to NULL
		}
		delete dummy;						// Delete dummy (eigenlijk item list)
    }
    return 0;
}

// This function adds a new item to the end of a doublelinked list
void list::push(item * itemObj) {
    if (this->end) {						// If end of list is not NULL,
		this->end->next = itemObj;			// point next to new itemObj
		itemObj->prev = this->end;			// and prev from itemObj to end.
    }
    this->end = itemObj;					// point end to new itemObj
    if (!this->begin)						// If begin is NULL make begin 
		this->begin = this->end;			// equal to end, (thus a single item list)
}

int main() {
	three_d	a(1, 0, 0), b(4, 5, 6), c(0.1,0.2,0.3), d, e, f;
	
	DNFractal fractal=DNFractal();
	
	f = fractal.iterate(a, b);
	cout << fractal.is_in_fractal(b, 10, 25) << " is in fract\n";
	cout << fractal.is_in_fractal(c, 10, 25) << " is in fract\n";	
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
				if (fractal.is_in_fractal(temp, 100, 25)){count++;}
				temp.show();
			}
		}
	}
	cout << count << endl;
	return(0);
}