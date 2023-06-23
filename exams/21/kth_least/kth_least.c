#include "minheap.h"
#include <stdlib.h>
#include <string.h>
void HeapsortMinHeap(Heap* h) {
    size_t origin_size = h->size; 

    while (h->size >= 2) {
        ElemSwap(HeapGetNodeValue(h, 0), HeapGetNodeValue(h, h->size - 1));
        h->size--;
        HeapMinMoveDown(h, 0);
    }
    h->size = origin_size;  
}
Heap* HeapifyMinHeap(ElemType* v, size_t v_size) {
    Heap* h = HeapCreateEmpty();
    h->size = v_size;
    h->data = malloc(sizeof(ElemType) * (v_size));
    memcpy(h->data, v, v_size * sizeof(ElemType));

    for (int i = (int)h->size / 2 - 1; i >= 0; i--) {
        HeapMinMoveDown(h, i);
    }
    return h;
}
int KthLeast(const int* v, size_t n, int k) {
    Heap* a = HeapifyMinHeap((ElemType*)v, n);
    HeapsortMinHeap(a);
    int minimo = 0;
    for (int i = a->size - 1; k>0; --i) {
        minimo = a->data[i];
        --k;
    }
    free(a->data);
    free(a);
    return minimo;
}