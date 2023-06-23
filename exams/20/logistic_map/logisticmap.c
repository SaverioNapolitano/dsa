#include <stdlib.h>
#include <stdio.h>

double LogisticMap(double x0, double r, int n) {
	if (n == 1)
		return r * x0 * (1 - x0);
	double a = LogisticMap(x0, r, n - 1);
	return r *a * (1 - a);
}
int main(int argc, char** argv) {
	if (argc != 4)
		return 1;
	char* endptr;
	double x0 = strtod(argv[1], &endptr);
	if (endptr[0] != 0 || x0 < 0 || x0>1)
		return 1;
	double r = strtod(argv[2], &endptr);
	if (endptr[0] != 0 || r < 0)
		return 1;
	int n = strtol(argv[3], &endptr, 10);
	if (endptr[0] != 0 || n < 0)
		return 1;
	
	double ris = LogisticMap(x0, r, n);
	printf("%lf", ris);

	return 0;

}