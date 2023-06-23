#include <stdlib.h>

#include "tree.h"

// Per ogni nodo (elemento `i`-esimo del vettore) considero come figlio sinistro
// l'elemento del vettore di indice `i * 2 + 1`, e come figlio destro l'elemento
// di indice `i * 2 + 2`.
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

extern void LevelOrder(const Node* t);

int main(void) {
    int v[] = { 7, 4, 8, 2, 5, 1 };
    size_t v_size = sizeof(v) / sizeof(int);
    Node* tree = TreeCreateEmpty();

    TreeWriteStdoutPreOrder(tree);
    TreeWriteStdoutInOrder(tree);
    TreeWriteStdoutPostOrder(tree);

    tree = TreeCreateFromVector(v, v_size);
    LevelOrder(tree);

    TreeWriteStdoutPreOrder(tree);
    TreeWriteStdoutInOrder(tree);
    TreeWriteStdoutPostOrder(tree);

    TreeDelete(tree);

    return EXIT_SUCCESS;
}