#include "minheap.h"
#include <stdlib.h>

extern bool IsHeap(const Heap* h);
int main(void) {
	Heap* h = malloc(sizeof(Heap));
	h->size = 5;
	h->data = malloc(h->size * sizeof(ElemType));
	h->data[0] = 1; h->data[1] = 3; h->data[2] = 4; h->data[3] = 6; h->data[4] = 4;
	bool e = IsHeap(h);

	return 0;
}