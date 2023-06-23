#include <stdlib.h>
#include <stdio.h>
#include <string.h>
static void CombinaMoneteRec(int b, const int*m, size_t m_size, int *nsol, int bcurr, int*vsol, size_t i, size_t j) {

	if (bcurr == b) {
		(*nsol)++;
		for (size_t k = 0; k < m_size; ++k) {
			printf("%d ", vsol[k]);
		}
		printf("\n");
		++j;
		return;
	}
	
	if(bcurr>b){
		return;
	}

	for (; j < m_size; ++j) {
		vsol[j] += 1;
		CombinaMoneteRec(b, m, m_size, nsol, bcurr + m[j], vsol, i+1, j);
		vsol[j] -= 1;
	}
}
int CombinaMonete(int b, const int* m, size_t m_size) {
	int nsol = 0;
	int bcurr = 0;
	int* vsol = calloc(m_size, sizeof(int));
	CombinaMoneteRec(b, m, m_size, &nsol, bcurr, vsol, 0, 0);
	free(vsol);
	return nsol;
}