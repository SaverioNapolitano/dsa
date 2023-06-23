#include "tree.h"

static void CountDominantRec(const Node* t, int *dom) {
	ElemType left = 0, right = 0;
	
	if (TreeIsLeaf(t))
		return;
	else {
		if (!TreeIsEmpty(TreeLeft(t))) {
			left = *TreeGetRootValue(TreeLeft(t));
		}
		if (!TreeIsEmpty(TreeRight(t))) {
			right = *TreeGetRootValue(TreeRight(t));
		}

		if (*TreeGetRootValue(t) > left + right) {
			(*dom)++;
		}
	}
	CountDominantRec(TreeLeft(t), dom);
	CountDominantRec(TreeRight(t), dom);
}
int CountDominant(const Node* t) {
	int n = 0;
	CountDominantRec(t, &n);
	return n;

}