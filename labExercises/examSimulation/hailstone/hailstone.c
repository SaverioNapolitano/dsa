#include <stdlib.h>
#include <stdio.h>
int Hailstone(int n, int elem) {
	if (n == 1) {
		printf("%d", n);
		return elem;
	}
	printf("%d, ", n);
	if (n % 2 == 0)
		Hailstone(n / 2, elem+1);
	else
		Hailstone(3 * n + 1, elem+1);
}
int main(int argc, char** argv) {
	if (argc != 2)
		return -1;
	int n = atoi(argv[1]);
	if (n <= 0)
		return 0;
	int elem = Hailstone(n, 0);
	elem += 1;
	return elem;
}