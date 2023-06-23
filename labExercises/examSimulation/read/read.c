#define _CRT_SECURE_NO_WARNINGS
#include "tree.h"
#include <stdlib.h>

static Node* TreeReadRec(FILE* f, Node* t, ElemType el) {
	
	if (ElemRead(f, &el) != 1)
		return TreeCreateEmpty();
	while (el == ' ' || el == '\n' || el == '\t' || el == '\v' || el == '\r' || el == '\f') {
		if (ElemRead(f, &el) != 1)
			return TreeCreateEmpty();
	}
	if (el == '.') {
		if (ElemRead(f, &el) != 1)
			return TreeCreateEmpty();
		while (el == ' ' || el == '\n' || el == '\t' || el == '\v' || el == '\r' || el == '\f') {
			if (ElemRead(f, &el) != 1)
				return TreeCreateEmpty();
		}
		t = TreeCreateRoot(&el, NULL, NULL);
		return t;
	}
	else
		t = TreeCreateRoot(&el, NULL, NULL);

	t->left = TreeReadRec(f, t->left, el);

	t->right = TreeReadRec(f, t->right, el);

	return t;
}
Node* TreeRead(const char* filename) {
	FILE* f = fopen(filename, "r");
	if (f == NULL)
		return NULL;
	ElemType root = 0;
	Node* t = TreeCreateEmpty();
	t = TreeReadRec(f, t, root);
	fclose(f);
	return t;
}