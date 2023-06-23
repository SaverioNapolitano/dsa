#include "tree.h"

static void TreeCountNodes(const Node* t, size_t* n) {
	if (TreeIsEmpty(t))
		return;
	(*n)++;
	TreeCountNodes(TreeLeft(t), n);
	TreeCountNodes(TreeRight(t), n);
}
static void IsomorfiRec(const Node* t1, const Node* t2, bool* iso, bool left1) {
	if ((TreeIsEmpty(t1) && !TreeIsEmpty(t2)) || (!TreeIsEmpty(t1) && TreeIsEmpty(t2))) {
		return;
	}
	if (TreeIsEmpty(t1) && TreeIsEmpty(t2))
		return;
	if (ElemCompare(TreeGetRootValue(t1), TreeGetRootValue(t2)) != 0) {
		*iso = false;
		return;
	}
	*iso = true;
	IsomorfiRec(TreeLeft(t1), TreeRight(t2), iso, true);
	if (!*iso) {
		if (left1)
			IsomorfiRec(TreeRight(t1), TreeRight(t2), iso, false);
		else
			IsomorfiRec(TreeLeft(t1), TreeLeft(t2), iso, true);
	}
	IsomorfiRec(TreeRight(t1), TreeLeft(t2), iso, false);
	if (!*iso) {
		if (left1)
			IsomorfiRec(TreeRight(t1), TreeRight(t2), iso, false);
		else
			IsomorfiRec(TreeLeft(t1), TreeLeft(t2), iso, true);
	}
}
bool Isomorfi(const Node* t1, const Node* t2) {
	if (TreeIsEmpty(t1) && TreeIsEmpty(t2))
		return true;
	bool iso = true;
	size_t n1 = 0;
	size_t n2 = 0;
	TreeCountNodes(t1, &n1);
	TreeCountNodes(t2, &n2);
	if (n1 != n2)
		return false;
	IsomorfiRec(t1, t2, &iso, true);
	return iso;
}