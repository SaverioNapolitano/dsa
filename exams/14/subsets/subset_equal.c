#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

static void SubsetEqualRec(int n, int s, int i, bool* vcurr) {

	if (i == n) {
		int somma = 0;
		for (int k = 0; k < i; ++k) {
			if(vcurr[k]!=0)
				somma += k + 1;
		}
		if (somma != s)
			return;
		printf("{ ");
		for (int j = 0; j < i; ++j) {
			if (vcurr[j] != 0) {
				printf("%i ", j + 1);
			}
		}
		printf("}, ");
		return;
	}

	vcurr[i] = 0;
	SubsetEqualRec(n, s, i + 1, vcurr);
	vcurr[i] = 1;
	SubsetEqualRec(n, s, i + 1, vcurr);


}


void SubsetEqual(int n, int s) {

	if (n <= 0 || s <= 0) {
		return;
	}

	bool* vcurr = calloc(n, sizeof(int));
	SubsetEqualRec(n, s, 0, vcurr);

	free(vcurr);
	
}