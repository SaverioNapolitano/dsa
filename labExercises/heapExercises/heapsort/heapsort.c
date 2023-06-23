#include "minheap.h"

void HeapMinHeapsort(Heap * h)
{
	size_t origin_size = h->size; 
	while (h->size >= 2) {
		ElemSwap(HeapGetNodeValue(h, 0), HeapGetNodeValue(h, h->size - 1));
		h->size--;
		HeapMinMoveDown(h, 0);
	}
	h->size = origin_size; 
}