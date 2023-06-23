#include "minheap.h"

void HeapMinMoveUpRec(Heap* h, int i) {
	if (i != 0 && ElemCompare(HeapGetNodeValue(h, i), HeapGetNodeValue(h, HeapParent(i))) < 0) {
		ElemSwap(HeapGetNodeValue(h, i), HeapGetNodeValue(h, HeapParent(i)));
		i = HeapParent(i);
	}
	else
		return;
	HeapMinMoveUpRec(h, i);
}