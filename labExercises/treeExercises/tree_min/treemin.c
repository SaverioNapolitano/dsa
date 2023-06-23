#include "tree.h"
#include <stdint.h>
const ElemType* BstTreeMin(const Node* n) {
	const ElemType* min = TreeGetRootValue(n);
	while (!TreeIsEmpty(n)) {
		min = TreeGetRootValue(n);
		n = TreeLeft(n);
	}
	return min;
}
static void TreeMinRec(const Node* n, const ElemType** min, size_t currlev, size_t *minlev) {
	if (TreeIsEmpty(n))
		return;
	else {
		if (ElemCompare(TreeGetRootValue(n), *min) <= 0) {
			if (currlev >= *minlev) {
				*min = TreeGetRootValue(n);
				*minlev = currlev;
			}
		}
	}
	TreeMinRec(TreeLeft(n), min, currlev + 1, minlev);
	TreeMinRec(TreeRight(n), min, currlev + 1, minlev);
}
const ElemType* TreeMin(const Node* n) {
	if (TreeIsEmpty(n))
		return NULL;

	const ElemType* min = TreeGetRootValue(n);
	size_t minlev = 0;

	TreeMinRec(n, &min, 0, &minlev);

	return min;
}