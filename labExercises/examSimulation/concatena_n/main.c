#include "list.h"

extern Item* ConcatenaN(Item** v, size_t v_size);

int main(void) {
	ElemType v1[] = { 1, 2, 3 };
	Item* i1 = ListCreateEmpty();
	for (size_t i = 0; i < 3; ++i) {
		i1 = ListInsertBack(i1, v1 + i);
	}


	ElemType v2[] = { 4, 5, 6 };
	Item* i2 = ListCreateEmpty();
	for (size_t i = 0; i < 3; ++i) {
		i2 = ListInsertBack(i2, v2 + i);
	}

	ElemType v3[] = { 7, 8, 9 };
	Item* i3 = ListCreateEmpty();
	for (size_t i = 0; i < 3; ++i) {
		i3 = ListInsertBack(i3, v3 + i);
	}

	Item** v = malloc(3*sizeof(Item**));
	v[0] = i1;
	v[1] = NULL;
	v[2] = i3;

	Item* ret = ConcatenaN(v, 3);

	return 0;

}