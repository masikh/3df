/*
 *  main.h
 *  
 *
 *  Created by Robert Nagtegaal on 5/7/11.
 *  Copyright 2011 alias Masikh. All rights reserved.
 *
 */

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

// This class describes an item from a list
class item {
public:
    item();						// Constructor for new item
    item(three_d vector, int iterations);// Constructor for new item with two integers for a digit and a temp variable
    ~item();					// Destructor of item object
    item *next;					// Pointer to next item
    item *prev;					// Pointer to previous item
    three_d vector;					// Integer to store one digit in
    int iterations;					// Integer to store one digit in
};

// This class implements a doubly linked list
class list {
public:
    list();						// Constructor for list
    ~list();					// Destructor for list
    void push(item * obj);		// Predeclaration for concatenation of item to end of list function
    item *shift();				// Predeclaration for removal of item at start of list function
    void unshift(item * obj);	// Predeclaration for adding item at start of list function
private:
	item *begin;				// Pointer to first item in list
    item *end;					// Pointer to last item in list
};
