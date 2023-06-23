#include "vettore.h"

void QuickSort(Vector* v, int first, int last) {
	int i, j;
	ElemType pivot;
	if (first < last) {
		i = first; j = last;
		pivot = v->data[(first + last) / 2];
		do {
			while (ElemCompare(&v->data[i], &pivot)==-1) i++;
			while (ElemCompare(&v->data[j], &pivot)==1) j--;
			if (i <= j) {
				ElemSwap(&v->data[i], &v->data[j]);
				i++, j--;
			}
		} while (i <= j);
		QuickSort(v, first, j);
		QuickSort(v, i, last);
	}
}
void VectorSort(Vector* v) {
	if (v == NULL)
		return;
	int first = 0;
	int last = v->size-1;
	QuickSort(v, first, last);
}