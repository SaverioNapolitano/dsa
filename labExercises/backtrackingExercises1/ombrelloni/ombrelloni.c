#include <stdio.h>
#include <stdlib.h>
static void OmbrelloniRec(int k, int n, int i, int* vcurr, int* nsol, int count, int c) {
	if (count + n - i < k)
		return;
	if (count == k) {
		(*nsol)++;
		printf("%4d)", *nsol);
		for (int j = 0; j < n; ++j) {
			printf(" %d", vcurr[j]);
		}
		printf("\n");
		return;
	}
	if (i == n)
		return;

	vcurr[i] = 0;
	OmbrelloniRec(k, n, i + 1, vcurr, nsol, count, c + 1);

	vcurr[i] = 1;
	if (vcurr[i - 1] == 1)
		return;
	OmbrelloniRec(k, n, i + 1, vcurr, nsol, count + 1, c + 1);
	vcurr[i] = 0;

}

int Ombrelloni(int k, int n) {
	if (k < 0 || n < 0)
		return 0;
	int* vcurr = malloc((sizeof(int) * n));
	int nsol = 0;
	OmbrelloniRec(k, n, 0, vcurr, &nsol, 0, 0);
	
	free(vcurr);
	return nsol;

}