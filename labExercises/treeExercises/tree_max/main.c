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

extern const ElemType* TreeMax(const Node* n);

int main(void) {
    int v[] = { 12, 4, 21, 0, 2, 5, 18, 77, 8, 9 };
    size_t v_size = sizeof(v) / sizeof(int);
    Node* tree = TreeCreateEmpty();

    tree = TreeCreateFromVector(v, v_size);
    const ElemType* massimo = TreeMax(tree);

}