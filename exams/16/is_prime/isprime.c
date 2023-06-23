#include <stdlib.h>
#include <stdio.h>

void IsPrime(int n, int i) {
	if (i == 1) {
		printf("true");
		return;
	}
	if (n % i == 0) {
		printf("false");
		return;
	}
	IsPrime(n, i - 1);
}

int main(int argc, char** argv) {
	if (argc != 2)
		return 1;
	char* endptr;
	int n = strtol(argv[1], &endptr, 10);
	if (endptr[0] != 0 || n<0)
		return 1;
	if (n == 0 || n == 1) {
		printf("false");
		return 0;
	}
	IsPrime(n, n / 2);
	return 0;
}