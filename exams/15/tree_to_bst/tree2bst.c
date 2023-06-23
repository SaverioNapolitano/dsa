#include "tree.h"

static void TreeBstPos(Node** ret, ElemType e) {
	Node* root = *ret;
	if (TreeIsEmpty(*ret)) {
		(*ret) = TreeCreateRoot(&e,NULL, NULL);
		return;
	}
	while (!TreeIsEmpty(*ret)) {
		if (ElemCompare(TreeGetRootValue(*ret), &e) >= 0) {
			if (TreeIsEmpty((*ret)->left)) {
				(*ret)->left = TreeCreateRoot(&e, NULL, NULL);
				(*ret) = root;
				return;
			}
			(*ret) = TreeLeft(*ret);
		}
		else {
			if (TreeIsEmpty((*ret)->right)) {
				(*ret)->right = TreeCreateRoot(&e, NULL, NULL);
				(*ret) = root;
				return;
			}
			(*ret) = TreeRight(*ret);
		}
	}

}
static void Tree2BstRec(const Node* t, Node** ret) {
	if (TreeIsEmpty(t))
		return;
	Tree2BstRec(TreeLeft(t), ret);
	TreeBstPos(ret, *TreeGetRootValue(t));
	Tree2BstRec(TreeRight(t), ret);
}
Node* Tree2Bst(const Node* t) {
	if (TreeIsEmpty(t))
		return NULL;
	Node* ret = TreeCreateEmpty();
	Tree2BstRec(t, &ret);
	return ret;
}