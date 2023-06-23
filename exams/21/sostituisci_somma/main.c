#include "tree.h"

extern void SostituisciSomma(Node* t);

int main(void) {

    ElemType e[] = { 2, 1, 3, 7, 4, 2, 4 };
    Node* t1 = TreeCreateRoot(&e[0],
        TreeCreateRoot(&e[1],
            TreeCreateRoot(&e[3], NULL, NULL),
            TreeCreateRoot(&e[4], NULL, NULL)),
        TreeCreateRoot(&e[2],
            TreeCreateRoot(&e[5], NULL, NULL),
            TreeCreateRoot(&e[6], NULL, NULL)));
    SostituisciSomma(t1);
    TreeDelete(t1);



    ElemType v[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13 };
    Node* t2 = TreeCreateRoot(&v[0],
        TreeCreateRoot(&v[1],
            TreeCreateRoot(&v[3],
                TreeCreateRoot(&v[5], NULL, NULL),
                TreeCreateRoot(&v[6],
                    TreeCreateRoot(&v[9], NULL, NULL),
                    NULL)),
            TreeCreateRoot(&v[4],
                TreeCreateRoot(&v[7], NULL, NULL),
                TreeCreateRoot(&v[8],
                    NULL,
                    NULL))),
        TreeCreateRoot(&v[1], TreeCreateRoot(&v[4],
            TreeCreateRoot(&v[8], NULL, NULL),
            TreeCreateRoot(&v[7],
                NULL,
                NULL)),
            TreeCreateRoot(&v[3],
                TreeCreateRoot(&v[6], NULL, TreeCreateRoot(&v[9], NULL, NULL)),
                TreeCreateRoot(&v[5],
                    NULL,
                    NULL))));
    TreeDelete(t2);

}