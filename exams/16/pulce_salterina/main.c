#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>
extern char* GuidaLaPulce(const int* f, size_t f_size, int a, int b, int n, int h, size_t* ret_size);

int main(void) {
	int f[] = { 1, 6, 2, 14, 5, 17, 4 };
	size_t f_size = sizeof(f) / sizeof(int);
	int a = 16;
	int b = 9;
	int	h = 7;
	int	n = 5;
	size_t ret_size = 0;
	char* ret = malloc(n * sizeof(char));
	ret = GuidaLaPulce(f, 5, a, b, n, h, &ret_size);

	_CrtDumpMemoryLeaks();
	return 0;
}