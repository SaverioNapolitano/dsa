#include <stdlib.h>

#include "tree.h"

extern bool CheckSumN(const Node* t, int n);

int main(void) {
    ElemType v[] = { 7, 6, 2, 1, 5, 8 };

    Node* t = TreeCreateRoot(v + 0, TreeCreateRoot(v + 1, TreeCreateRoot(v + 2, TreeCreateRoot(v + 3, NULL, NULL), NULL), TreeCreateRoot(v + 4, NULL, NULL)), TreeCreateRoot(v + 5, NULL, NULL));

    bool ris = CheckSumN(t, 7);

    TreeDelete(t);

    return EXIT_SUCCESS;
}