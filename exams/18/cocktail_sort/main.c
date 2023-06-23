#include <stdlib.h>

extern void CocktailSort(int* v, size_t v_size);

int main(void) {
	int v[] = { 3, 6, 2, 9, 0, 7, 1, -4, 8 };
	CocktailSort(v, 9);

	return 0;
}