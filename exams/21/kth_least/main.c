#include "minheap.h"

extern int KthLeast(const int* v, size_t n, int k);
int main(void) {
    int *v = malloc(sizeof(ElemType) * 5);

    v[0] = 7;
    v[1] = 2;
    v[2] = 3;
    v[3] = 4;
    v[4] = 5;

    int r = KthLeast(v, 5, 4);
    
    return 0;
}