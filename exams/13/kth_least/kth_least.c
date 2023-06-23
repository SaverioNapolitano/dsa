#include "minheap.h"
#include <string.h>
#include <stdlib.h>
int Confronta(const void*a, const void*b) {
	const ElemType* pa = a;
	const ElemType* pb = b;

	return (ElemCompare(pa, pb));
}
ElemType KthLeast(const Heap* h, int k) {
	ElemType* v = malloc(h->size * sizeof(ElemType));
	memcpy(v, h->data, h->size * sizeof(ElemType));
	qsort(v, h->size, sizeof(ElemType), &Confronta);
	ElemType min = v[k - 1];
	free(v);
	return min;
}