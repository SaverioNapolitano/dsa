#include "tree.h"
#include <stdlib.h>

extern bool TreeIsMirror(const Node* t);

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

int main(void) {
    int v[] = { 0, 1, 1, 4, 2, 2, 4 };
    size_t v_size = sizeof(v) / sizeof(int);
    Node* tree = TreeCreateEmpty();

    tree = TreeCreateFromVector(v, v_size);
    
    bool m = TreeIsMirror(tree);

    TreeDelete(tree);

    return EXIT_SUCCESS;
}