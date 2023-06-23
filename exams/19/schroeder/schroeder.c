#include <stdio.h>
#include <stdlib.h>

int Schroeder(int n) {
	if (n == 0) {
		return 1;
	}
	if (n == 1) {
		return 2;
	}

	return (6 * n - 3) * Schroeder(n-1) / (n + 1) - (n - 2) * Schroeder(n-2) / (n + 1);
}
int main(int argc, char** argv) {
	if (argc != 2)
		return 1;
	char* endptr;
	int n = strtol(argv[1], &endptr, 10);
	if (endptr[0] != 0 || n<0)
		return 1;
	int ret = Schroeder(n);
	printf("%i", ret);
	return 0;
}