#include <iostream>
#include "triangle.h"

using namespace std;

triangle::triangle() {
	a = 0;
	b = 0;
	c = 0;

	cout << "Konstruktor triangle()" << endl;
}
triangle::triangle(double side_a, double side_b, double side_c)
{
	calc_c(side_a, side_b);
	cout << "Konstruktor triangle(a, b, c)" << endl;
}

triangle::~triangle() {
	cout << "Destruktor" << endl;
}

double triangle::show_length_a(void) {
	cout << "strona a - " << a << endl;
	return a;
}

double triangle::show_length_b(void) {
	cout << "strona b - " << b << endl;
	return b;
}

double triangle::show_length_c(void) {
	cout << "strona c - " << c << endl;
	return c;
}

double triangle::calc_c(double side_a, double side_b) {

	c =  sqrt(side_a * side_a + side_b * side_b);	

	return c;
}
