#include "tree.h"

Node* BstInsert(const ElemType* e, Node* n) {
	if (TreeIsEmpty(n)) {
		Node* t = TreeCreateRoot(e, NULL, NULL);
		return t;
	}
	Node* fake_root = n;
	Node* prev = n;
	while (!TreeIsEmpty(n)) {
		if (ElemCompare(e, TreeGetRootValue(n)) <= 0) {
			prev = n;
			n = TreeLeft(n);
		}
		else {
			prev = n;
			n = TreeRight(n);
		}
	}
	if (ElemCompare(e, TreeGetRootValue(prev)) <= 0) {
		prev->left = TreeCreateRoot(e, NULL, NULL);
	}
	if (ElemCompare(e, TreeGetRootValue(prev)) > 0) {
		prev->right = TreeCreateRoot(e, NULL, NULL);
	}
	return fake_root;
}
static void BstInsertRecRec(const ElemType* e, Node* n, Node* prev) {

	if (TreeIsEmpty(n)) {
		if (ElemCompare(e, TreeGetRootValue(prev)) <= 0) {
			prev->left = TreeCreateRoot(e, NULL, NULL);
			return;
		}
		prev->right = TreeCreateRoot(e, NULL, NULL);
		return;
	}
	if (ElemCompare(e, TreeGetRootValue(n)) <= 0) {
		prev = n;
		BstInsertRecRec(e, TreeLeft(n), prev);
	}
	else {
		prev = n;
		BstInsertRecRec(e, TreeRight(n), prev);
	}
}
Node* BstInsertRec(const ElemType* e, Node* n) {
	if (TreeIsEmpty(n)) {
		Node* t = TreeCreateRoot(e, NULL, NULL);
		return t;
	}

	 BstInsertRecRec(e, n, n);
	 return n;
}