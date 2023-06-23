#include "minheap.h"
#include <stdlib.h>
extern ElemType KthLeast(const Heap* h, int k);

int main(void) {
	ElemType d[] = { -1, 3, 6, 4 };
	Heap* h = malloc(sizeof(Heap));
	h->data = malloc(4 * sizeof(ElemType));
	h->size = 4;
	for (int i = 0; i < 4; ++i) {
		h->data[i] = d[i];
	}
	ElemType ret = KthLeast(h, 4);

	return 0;
}