#include <string.h>
#include <ctype.h>
#include <stdio.h>

void tosmall(char *x) {
	while (*x) {

		if (('A' <= *x) && (*x <= 'Z')) {
			
			*x += ('a' - 'A');
		}

		x++;
	}	
}

void print_result(float x) {		
	printf("result: %.3f \n", x );
}

void print_result(int x) {
	printf("result: %d \n", x );
}

int intorfloat(char *arg) {
	int count = 0;

	tosmall(arg);

	while (*arg)
	{
		if (('.' == *arg) || (',' == *arg)) {
			if (count == 1) {
				return -2;
			}
			else {
				*arg = '.';
				count++;
			}
		}
		else if (('a' <= *arg) && (*arg <= 'z')) {
			return -1;
		}
		
		arg++;
	}

	return count;
}