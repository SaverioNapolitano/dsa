#include <stdlib.h>
#include <stdio.h>
double Concentrazione(int n) {
	if (n == 0)
		return 0;

	return 0.2 + 0.3 * Concentrazione(n - 1);
}
int main(int argc, char** argv) {

	if (argc != 2)
		return 1;

	int n = atoi(argv[1]);
	if (n < 1)
		return 1;

	double c = Concentrazione(n - 1);
	printf("%lf", c);

	return 0;
}