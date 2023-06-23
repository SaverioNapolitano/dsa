#include "tree.h"

extern bool Isomorfi(const Node* t1, const Node* t2);

int main(void) {
	ElemType v[] = { 1, 2, 3, 4, 5, 6, 7, 8 };

	Node* t1 = TreeCreateRoot(v + 0, TreeCreateRoot(v + 1, TreeCreateRoot(v+3, TreeCreateRoot(v+6, NULL, NULL), TreeCreateRoot(v+7, NULL, NULL)), TreeCreateRoot(v+4, NULL, NULL)), 
		TreeCreateRoot(v + 2, TreeCreateRoot(v+5, NULL, NULL), NULL));
	Node* t2 = TreeCreateRoot(v + 0, TreeCreateRoot(v+2, TreeCreateRoot(v+5, NULL, NULL), NULL), TreeCreateRoot(v+1, TreeCreateRoot(v+3, TreeCreateRoot(v+7, NULL, NULL), 
		TreeCreateRoot(v+6, NULL, NULL)), TreeCreateRoot(v+4, NULL, NULL)));

	Node* t3 = TreeCreateRoot(v + 0, TreeCreateRoot(v + 1, NULL, NULL), TreeCreateRoot(v + 2, TreeCreateRoot(v + 3, NULL, NULL), NULL));
	Node* t4 = TreeCreateRoot(v + 0, TreeCreateRoot(v + 1, NULL, NULL), TreeCreateRoot(v + 2, NULL, NULL));

	bool i = Isomorfi(t3, t4);

	return 0;
}