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
extern double Mediano(const Node* t);
int main(void) {
    int v[] = { 11, 5, 3, -1, 4, 9, 8, 7, 10, 12, 13 };
    size_t v_size = sizeof(v) / sizeof(int);
    Node* tree = TreeCreateEmpty();

    tree = TreeCreateRoot(v+0, TreeCreateRoot(v+1, TreeCreateRoot(v+2, TreeCreateRoot(v+3, NULL, NULL), TreeCreateRoot(v+4, NULL, NULL)),
            TreeCreateRoot(v+5, TreeCreateRoot(v+6, TreeCreateRoot(v+7, NULL, NULL), NULL), TreeCreateRoot(v+8, NULL, NULL))), TreeCreateRoot(v+9, NULL, TreeCreateRoot(v+10, NULL, NULL)));


    TreeWriteStdoutInOrder(tree);
    double r = Mediano(tree);


    TreeDelete(tree);

    return EXIT_SUCCESS;
}