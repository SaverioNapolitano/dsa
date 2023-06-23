#include <stdlib.h>
#include <stdio.h>
static void StepsRec(int n, int* vsol, int* nsol, int i, int sum, int v_size) {
	if (sum > n)
		return;
	if (sum == n) {
		(*nsol)++;
		printf("[");
		int k = 0;
		for (; k < v_size - 2 ; ++k) {
			printf("%d, ", vsol[k]);
		}
		printf("%d], ", vsol[k]);
		return;
	}

	for (int j = 0; j < 3; ++j) {
		vsol[i] = j + 1;
		StepsRec(n, vsol, nsol, i + 1, sum + vsol[i], v_size + 1);
		vsol[i] = 0;
	}
}

int Steps(int n) {
	if (n <= 0)
		return 0;
	int nsol = 0;
	int* vsol = calloc(n, sizeof(int));
	StepsRec(n, vsol, &nsol, 0, 0, 1);
	free(vsol);
	return nsol;

}