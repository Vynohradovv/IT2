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

void doPliku(char *argv[], float var) {
	FILE* fptr;
	fptr = fopen("log.txt", "a");

	if (fptr) {
		fprintf(fptr, "%s %s %s %s \n", argv[0], argv[1], argv[2], argv[3]);
		fprintf(fptr, "result: %.3f\n\n", var);
		fclose(fptr);
	}
	else {
		printf("Nie udalo sie otworzyc pliku \n");
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