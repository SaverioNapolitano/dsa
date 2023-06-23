#include <stdlib.h>

extern void PancakeSort(int* v, size_t v_size);

int main(void) {
	int v[] = { 3, 6, 2, 9, 0, 7, 1, -4, 8, 10, 45, 100, 23, 88, -12, 37, -51 };
	size_t v_size = sizeof(v) / sizeof(int);
	PancakeSort(v, v_size);

	return 0;
}