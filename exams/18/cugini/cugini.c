#include "tree.h"

bool CuginiRec(const Node* t, int i, const Node** a_father, const Node** b_father, int *ia, int *ib, ElemType *ta, ElemType *tb, const Node *a_fake_father, const Node *b_fake_father) {
	
	bool ret;
	if (TreeIsEmpty(t))
		return false;
	if (ElemCompare(TreeGetRootValue(t), ta) == 0) {
		*ia = i;
		*a_father = a_fake_father;
	}
	if (ElemCompare(TreeGetRootValue(t), tb) == 0) {
		*ib = i;
		*b_father = b_fake_father;
	}
	if ((*ia) >= 0 && (*ib) >= 0) {
		if ((*ia) == 0 || (*ib) == 0) {
			ret = false;
		}
		else if ((*ia) != (*ib))
			ret=false;
		else if ((*a_father) == (*b_father))
			ret=false;
		else ret=true;

		return ret;
	}
	
	ret = CuginiRec(TreeLeft(t), i + 1, a_father, b_father, ia, ib, ta, tb, t, t);
	if (ret == false)
		ret = CuginiRec(TreeRight(t), i + 1, a_father, b_father, ia, ib, ta, tb, t, t);

	return ret;

}
bool Cugini(const Node* t, int a, int b) {

	if (t == NULL)
		return false;

	int ia = -1;
	int ib = -1;
	const Node* a_father = NULL;
	const Node* b_father = NULL;
	return CuginiRec(t, 0, &a_father, &b_father, &ia, &ib, &a, &b, NULL, NULL);

}