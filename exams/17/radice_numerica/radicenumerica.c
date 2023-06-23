#include <stdlib.h>
#include <stdio.h>
#include <math.h>

void RadiceNumerica(int n, int somma) {

	if (somma < 10 && n==0) {
		printf("%d", somma);
		return;
	}
	if (n == 0) {
		n = somma;
		somma = 0;
	}

	RadiceNumerica(n/10, somma + n%10);
}
int main(int argc, char** argv) {
	if (argc != 2)
		return 1;
	
	char* endptr;
	int n = strtol(argv[1], &endptr, 0);
	if (endptr[0] != 0 || n<0)
		return 1;
	if (n == 0) {
		printf("0");
		return 0;
	}
	RadiceNumerica(n, 0);

	return 0;

}