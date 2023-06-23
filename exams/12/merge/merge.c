#include "minheap.h"
#include <stdlib.h>
#include <string.h>
Heap* MergeHeap(const Heap* h1, const Heap* h2) {
	Heap* h = HeapCreateEmpty();
	h->size = h1->size;
	h->data = malloc(h->size * sizeof(ElemType));
	memcpy(h->data, h1->data, h->size * sizeof(ElemType));
	h->size += h2->size;
	h->data = realloc(h->data, h->size * sizeof(ElemType));
	for (size_t i = h1->size, j = 0; i < h->size&&j<h2->size; ++i, ++j) {
		h->data[i] = h2->data[j];
		HeapMinMoveUp(h, i);
	}
	return h;
}