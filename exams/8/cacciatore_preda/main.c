#include <stdlib.h>

extern int* CacciatorePreda(const char* v, size_t v_size, int u);

int main(void) {
	char v[] = { 'C', 'C', 'C' };
	size_t v_size = sizeof(v) / sizeof(char);
	int* ret = malloc(v_size * sizeof(int));
	ret = CacciatorePreda(v, v_size, 1);

	return 0;
}