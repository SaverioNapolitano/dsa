#include "tree.h"

extern Node* CreateMaxBinTree(const ElemType* v, size_t v_size);

int main(void) {
	ElemType v[] = { 3, 2, 1, 6, 0, 5 };
	Node* tree = CreateMaxBinTree(v, 6);



	return 0;
}