#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <limits.h>
#include <string.h>
#include <stdbool.h>
void TiroAllaFune(int sommatot, int asomma, int n, int i, int insieme[], int* asol, int* diffsol, int* acurr) {
	int tmp;

	if (i == n / 2) {
		if (abs(asomma - (sommatot - asomma)) < *diffsol) {
			memcpy(asol, insieme, n / 2 * sizeof(int));
			*diffsol = abs(asomma - (sommatot - asomma));
		}
		return;
	}

	for (int j = i; j < n; j++) {
		tmp = insieme[i];
		insieme[i] = insieme[j];
		insieme[j] = tmp;
		TiroAllaFune(sommatot, asomma + insieme[i], n, i + 1, insieme, asol, diffsol, acurr);
		tmp = insieme[i];
		insieme[i] = insieme[j];
		insieme[j] = tmp;
	}

}

int main(int argc, char** argv) {
	if (argc == 1) {
		printf("{ }, { }");
		return EXIT_FAILURE;
	}
	char* endptr;
	size_t l = 0;
	int diffsol = INT_MAX;
	int* insieme = malloc((argc - 1) * sizeof(int));
	int sommatot = 0;
	int asomma = 0;
	for (int j = 1; j < argc; ++j) {
		insieme[l] = strtol(argv[j], &endptr, 10);
		if (endptr[0] != 0)
			break;
		sommatot += insieme[l];
		++l;
	}
	int* acurr = malloc((argc - 1) / 2 * sizeof(int));
	int* asol = malloc((argc - 1) / 2 * sizeof(int));
	int* bsol = malloc((argc - 1 - (argc - 1) / 2) * sizeof(int));
	TiroAllaFune(sommatot, asomma, argc - 1, 0, insieme, asol, &diffsol, acurr);

	bool presente = false;
	int m = 0;
	for (int j = 0; j < argc - 1; ++j) {
		for (int k = 0; k < (argc - 1) / 2; ++k) {
			if (asol[k] == insieme[j]) {
				presente = true;
				break;
			}
		}
		if (!presente) {
			bsol[m] = insieme[j];
			++m;
		}
		presente = false;
	}
	printf("{ ");
	for (int j = 0; j < (argc - 1) / 2 - 1; ++j) {
		printf("%i, ", asol[j]);
	}
	printf("%i }, { ", asol[(argc-1) / 2 - 1]);
	for (int j = 0; j < argc - 1 - (argc - 1) / 2 - 1; ++j) {
		printf("%i, ", bsol[j]);
	}
	printf("%i }", bsol[argc - 1 - (argc - 1) / 2 - 1]);

	free(insieme);
	free(acurr);
	free(asol);
	free(bsol);

	return EXIT_SUCCESS;
}