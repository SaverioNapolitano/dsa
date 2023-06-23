#include "tree.h"

extern Node* Tree2Bst(const Node* t);

int main(void) {
	ElemType v[] = { 6, 2, 3, 8, 5, 9, 3};

	Node* t = TreeCreateRoot(v + 0, TreeCreateRoot(v + 1, TreeCreateRoot(v + 2, NULL, NULL), TreeCreateRoot(v + 3, NULL, TreeCreateRoot(v + 4, NULL, NULL))), TreeCreateRoot(v + 5, NULL, TreeCreateRoot(v + 6, NULL, NULL)));

	TreeWriteStdoutInOrder(t);

	Node* r = NULL;
	r = Tree2Bst(t);

	TreeWriteStdoutInOrder(r);

	return 0;

}