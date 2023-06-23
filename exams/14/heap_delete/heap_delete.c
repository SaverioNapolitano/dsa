#include "minheap.h"
#include <stdlib.h>
void HeapDeleteNode(Heap* h, int k) {
	if (k < 0 || k >= (int)h->size)
		return;

	h->data[k] = h->data[h->size - 1];

	h->data = realloc(h->data, h->size-- * sizeof(ElemType));
	HeapMinMoveDown(h, k);
}

