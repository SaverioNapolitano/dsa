#include "tree.h"

static void EquivalentiRec(const Node* t1, const Node* t2, bool* eq) {
	if (!eq)
		return;
	if ((TreeIsEmpty(t1) && !TreeIsEmpty(t2)) || (!TreeIsEmpty(t1) && TreeIsEmpty(t2))) {
		*eq = false;
		return;
	}
	if (TreeIsEmpty(t1) && TreeIsEmpty(t2))
		return;
	if ((TreeIsLeaf(t1) && !TreeIsLeaf(t2)) || (!TreeIsLeaf(t1) && TreeIsLeaf(t2))) {
		*eq = false;
		return;
	}
	if (TreeIsLeaf(t1) && TreeIsLeaf(t2)) {
		if (t1->value % t2->value != 0 && t2->value % t1->value != 0) {
			*eq = false;
		}
		return;
	}
	if (!TreeIsLeaf(t1) && !TreeIsLeaf(t2)) {
		if (ElemCompare(TreeGetRootValue(t1), TreeGetRootValue(t2)) != 0) {
			*eq = false;
			return;
		}
	}
	EquivalentiRec(TreeLeft(t1), TreeLeft(t2), eq);
	EquivalentiRec(TreeRight(t1), TreeRight(t2), eq);
}
bool Equivalenti(const Node* t1, const Node* t2) {
	if (TreeIsEmpty(t1) && TreeIsEmpty(t2))
		return true;
	bool eq = true;
	EquivalentiRec(t1, t2, &eq);
	return eq;
}