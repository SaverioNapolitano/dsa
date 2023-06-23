#include "tree.h"
#include <stdint.h>
#include <string.h>
#include <stdlib.h>

static void CreateMaxBinTreeRec(ElemType*v, size_t v_size, ElemType max, size_t maxpos, Node **n, bool *used) {
	
	bool full = true;
	for (size_t j = 0; j < v_size; ++j) {
		if (!used[j]) {
			full = false;
			break;
		}
	}
	if (full)
		return;
	for (size_t i = 0; i < v_size; ++i) {
		if (used[i])
			break;
		if (ElemCompare(&max, &v[i]) < 0) {
			max = ElemCopy(&v[i]);
			maxpos = i;
		}
	}
	if (used[maxpos]) {
		return;
	}
	used[maxpos] = true;
	*n = TreeCreateRoot(&max, NULL, NULL);
	if (maxpos != 0)
		CreateMaxBinTreeRec(v, v_size, INT32_MIN, maxpos, &(*n)->left, used);
	else
		CreateMaxBinTreeRec(v + maxpos + 1, v_size, INT32_MIN, maxpos, &(*n)->right, used + maxpos + 1);

	CreateMaxBinTreeRec(v + maxpos + 2, v_size, INT32_MIN, maxpos, &(*n)->right, used + maxpos + 2);
	
}
Node* CreateMaxBinTree(const ElemType* v, size_t v_size) {
	if (v == NULL)
		return NULL;
	Node* n = TreeCreateEmpty();
	ElemType max = 0;
	size_t maxpos = 0;
	bool* used = calloc(v_size, sizeof(bool));
	CreateMaxBinTreeRec(v, v_size, max, -1, &n, used);

	free(used);
	return n;
}