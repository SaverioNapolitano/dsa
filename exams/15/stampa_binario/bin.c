#include <stdlib.h>
#include <stdio.h>

void PrintBin(int n, int ret) {
	if (n == 0) {
		return;
	}
	ret = n % 2;
	PrintBin(n / 2, ret);
	printf("%d", ret);

}
int main(int argc, char** argv) {
	if (argc != 2)
		return 1;
	char* endptr;
	int n = strtol(argv[1], &endptr, 10);
	if (endptr[0] != 0 || n < 0)
		return 1;
	if (n == 0) {
		printf("%d", n);
	}
	else {
		PrintBin(n, 0);
	}
	return 0;
}