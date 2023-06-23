#include "minheap.h"

void HeapMinMoveDownRec(Heap* h, int i) {
    int l, r, smallest = i;
    bool done = false;
    if (!done) {
        done = true;
        l = HeapLeft(i);
        r = HeapRight(i);

        if ((l < (int)h->size) && ElemCompare(HeapGetNodeValue(h, l), HeapGetNodeValue(h, smallest)) < 0) {
            smallest = l;
        }

        if ((r < (int)h->size) && ElemCompare(HeapGetNodeValue(h, r), HeapGetNodeValue(h, smallest)) < 0) {
            smallest = r;
        }

        if (smallest != i) {
            ElemSwap(HeapGetNodeValue(h, i), HeapGetNodeValue(h, smallest));
            i = smallest;
            done = false;
        }

    }
    if (done == true)
        return;
    HeapMinMoveDownRec(h, i);
}
