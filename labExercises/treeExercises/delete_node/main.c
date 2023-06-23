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

extern Node* DeleteBstNode(Node* n, const ElemType* key);

int main(void) {
    int v[] = { 12, 4, NULL, NULL, 5 };
    size_t v_size = sizeof(v) / sizeof(int);
    Node* tree = TreeCreateEmpty();

    tree = TreeCreateFromVector(v, v_size);

    ElemType key = 12;
    Node* ret_tree = DeleteBstNode(tree, &key);
    TreeDelete(tree);

    return EXIT_SUCCESS;
}