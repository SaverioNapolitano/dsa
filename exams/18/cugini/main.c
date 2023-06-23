#include <stdlib.h>

#include "tree.h"

Node* TreeCreateFromVectorRec(const int* v, size_t v_size, int i) {
    if (i >= (int)v_size) {
        return NULL;
    }

    Node* l = TreeCreateFromVectorRec(v, v_size, i * 2 + 1);
    Node* r = TreeCreateFromVectorRec(v, v_size, i * 2 + 2);

    return TreeCreateRoot(&v[i], l, r);
}

Node* TreeCreateFromVector(const int* v, size_t v_size) {
    return TreeCreateFromVectorRec(v, v_size, 0);
}

extern bool Cugini(const Node* t, int a, int b);

int main(void) {
    int v[] = { 6, 2, 9, 3, 8, 4, 5};
    size_t v_size = sizeof(v) / sizeof(int);
    Node* tree = TreeCreateEmpty();

    tree = TreeCreateFromVector(v, v_size);

    bool c = Cugini(tree, 5, 6);

    TreeDelete(tree);

    return EXIT_SUCCESS;
}