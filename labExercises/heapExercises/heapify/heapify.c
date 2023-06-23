#include "minheap.h"
#include <string.h>
Heap* HeapMinHeapify(const ElemType* v, size_t v_size) {
	Heap* h = HeapCreateEmpty();
	h->size = v_size;
	h->data = malloc(sizeof(ElemType) * (v_size));
	memcpy(h->data, v, v_size * sizeof(ElemType));
	for (int i = (int)h->size / 2 - 1; i >= 0; i--) {
		HeapMinMoveDown(h, i);
	}
	return h;
}