
#include <stdlib.h>

int stack_size = 0;

int stack_index = 1;

int* stack_table;

bool StackInit(int size) {

	stack_table = (int*)malloc(size * sizeof(int));

	if (stack_table != NULL) {

		stack_size = size + 1;

		return true;

	}

	return false;
}

void StackDeinit(void) {

	free(stack_table);	
}

int isStackEmpty(void) {

	return (stack_index == 1) ? 1 : 0;
}

int isStackFull(void) {

	return (stack_index == stack_size) ? 1 : 0;
}

int Pop(void) {

	if (!isStackEmpty()) {
		stack_index--;
		return stack_table[stack_index];
	}

	return stack_table[1];
}

int Top(void) {

	if (!isStackEmpty()) {
	
		return stack_table[stack_index - 1];
	}

	return stack_table[1];
}

void Push(int val) {

	if (!isStackFull()) {

		stack_table[stack_index] = val;
		stack_index++;
	}
}