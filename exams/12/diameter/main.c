#include <stdlib.h>

#include "tree.h"

extern int Diameter(const Node* t);

int main(void) {
    int v[] = { 0, 1, 3, 5, 6, 9, 4, 7, 8, 9, 2 };
    
    Node* tree = TreeCreateRoot(v + 0, TreeCreateRoot(v + 1, TreeCreateRoot(v + 2, TreeCreateRoot(v + 3, NULL, NULL), TreeCreateRoot(v + 4, TreeCreateRoot(v + 5, NULL, NULL), NULL)),
        TreeCreateRoot(v + 6, TreeCreateRoot(v + 7, NULL, NULL), TreeCreateRoot(v + 8, NULL, TreeCreateRoot(v + 9, NULL, NULL)))), TreeCreateRoot(v+10, NULL, NULL));

    
    TreeWriteStdoutInOrder(tree);
    
    
    int n = Diameter(tree);
    
    TreeDelete(tree);

    return EXIT_SUCCESS;
}