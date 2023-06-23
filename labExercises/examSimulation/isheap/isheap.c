#include "minheap.h"

bool IsHeap(const Heap* h) {

	if (h == NULL)
		return false;
	if (h->size == 0 || h->size==1)
		return true;

	for (int i = 0; i < (int)h->size/2-1; ++i) {
		if (h->data[HeapLeft(i)] < h->data[i] || h->data[HeapRight(i)] < h->data[i])
			return false;
	}

	return true;
}