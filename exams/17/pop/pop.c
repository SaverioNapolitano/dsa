#include "minheap.h"

bool Pop(Heap* h, ElemType* e) {
	if (HeapIsEmpty(h))
		return false;
	*e = *HeapGetNodeValue(h, 0);
	ElemSwap(HeapGetNodeValue(h, 0), HeapGetNodeValue(h, h->size - 1));
	h->size--;
	HeapMinMoveDown(h, 0);
	return true;
}