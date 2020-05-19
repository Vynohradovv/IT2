#pragma once

class triangle {
private:

	double a;
	double b;
	double c;

public:

	triangle();
	triangle(double side_a, double side_b, double side_c = 0);
	~triangle();

	double show_length_a(void);
	double show_length_b(void);
	double show_length_c(void);

	double calc_c(double side_a, double side_b);
	
};