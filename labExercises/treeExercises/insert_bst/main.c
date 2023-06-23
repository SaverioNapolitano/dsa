#include "tree.h"
//All'esame si può avere un file che contiene solo il main con la creazione di albero/lista/heap di esempio
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

extern Node* BstInsertRec(const ElemType* e, Node* n);
int main(void) {

	/*ElemType e[] = { 0,1,2,3,4,5,6,7,8,9 };

	Node* n = TreeCreateEmpty();
	n = TreeCreateRoot(
		e + 0,
		TreeCreateRoot(e + 1, NULL, NULL),
		TreeCreateRoot(e + 2, NULL, NULL)
	);*/
        int v[] = { 12, 4, 21, 0, 5, 18, 77, 2, 8, 9 };
        size_t v_size = sizeof(v) / sizeof(int);
        Node* tree = TreeCreateEmpty();

        tree = TreeCreateFromVector(v, v_size);
        ElemType e = 13;
        tree = BstInsertRec(&e, tree);


}
