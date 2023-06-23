#include "tree.h"
#include <stdlib.h>
static void CheckSumNRecNode(const Node* t, ElemType n, ElemType sum, bool *ret, int nodes, bool doubled) {

	if (*ret)
		return;
	if (ElemCompare(&sum, &n) == 0 && nodes==2 && !doubled) {
		*ret = true;
		return;
	}
	if(ElemCompare(&sum, TreeGetRootValue(t))>0 && (nodes >= 2||doubled))
		sum -= *TreeGetRootValue(t);

	if (!TreeIsEmpty(t->left))
		if (ElemCompare(&sum, TreeGetRootValue(t->left)) != 0) {
			if (nodes == 2)
				nodes--;
			CheckSumNRecNode(TreeLeft(t), n, sum + *TreeGetRootValue(t->left), ret, nodes + 1, false);
		}
		else
			CheckSumNRecNode(TreeLeft(t), n, sum + *TreeGetRootValue(t->left), ret, nodes, true);
	else
		return;

	if (!TreeIsEmpty(t->right))
		if (ElemCompare(&sum, TreeGetRootValue(t->right)) != 0) {
			if (nodes == 2)
				--nodes;
			CheckSumNRecNode(TreeRight(t), n, sum + *TreeGetRootValue(t->right), ret, nodes + 1, false);
		}
		else	
			CheckSumNRecNode(TreeRight(t), n, sum + *TreeGetRootValue(t->right), ret, nodes, true);
	else
		return;

}
static void CheckSumNRec(const Node* t, ElemType n, ElemType sum, bool* ret, const Node* fake_t) {

	if (*ret)
		return;
	if (TreeIsEmpty(fake_t))
		return;
	if (!TreeIsEmpty(fake_t->left))
		CheckSumNRecNode(t, (ElemType)n, *TreeGetRootValue(TreeLeft(fake_t)), ret, 1, false);
	if (!TreeIsEmpty(fake_t->right))
		CheckSumNRecNode(t, (ElemType)n, *TreeGetRootValue(TreeRight(fake_t)), ret, 1, false);
	if (TreeIsLeaf(fake_t))
		return;

	CheckSumNRec(t, n, sum, ret, TreeLeft(fake_t));

	CheckSumNRec(t, n, sum, ret, TreeRight(fake_t));
}
bool CheckSumN(const Node* t, int n) {
	if (TreeIsEmpty(TreeLeft(t)) && TreeIsEmpty(TreeRight(t)))
		return false;
	bool r = false;
	CheckSumNRecNode(t, n, *TreeGetRootValue(t), &r, 1, false);
	if (r)
		return r;
	CheckSumNRec(t, (ElemType)n, *TreeGetRootValue(t), &r, t);
	return r;
}