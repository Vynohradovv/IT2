#include "funkcje_swap.h"


void swap(int* a, int* b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

void swap_tab_wsk(int* tab_a, int* tab_b, int ilosc_elementow_do_zamiany) {
	swap(tab_a, tab_b);
}