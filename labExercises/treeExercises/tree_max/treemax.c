#include "tree.h"
#include <stdint.h>
const ElemType* BstTreeMax(const Node* n) {
	const ElemType* max = TreeGetRootValue(n);
	while (!TreeIsEmpty(n)) {
		max = TreeGetRootValue(n);
		n = TreeRight(n);
	}
	return max;
}
static void TreeMaxRec(const Node* n, const ElemType **max) {
	if (TreeIsEmpty(n))
		return;
	else {
		if (ElemCompare(TreeGetRootValue(n),*max)>0) {
			*max = TreeGetRootValue(n);
		}
	}
	TreeMaxRec(TreeLeft(n), max);
	TreeMaxRec(TreeRight(n), max);
}
const ElemType* TreeMax(const Node* n) {
	if (TreeIsEmpty(n))
		return NULL;

	const ElemType *max = TreeGetRootValue(n);
	
	TreeMaxRec(n, &max);

	return max;
}