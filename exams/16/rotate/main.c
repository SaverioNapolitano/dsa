#include "list.h"

extern Item* Rotate(Item* i, int n);

int main(void) {
	ElemType v[] = { 1, 3, 4, 7, 8 };
	size_t size = sizeof(v) / sizeof(ElemType);
	Item* i = ListCreateEmpty();
	for (size_t j = 0; j < size; ++j) {
		i = ListInsertBack(i, v + j);
	}
	i = Rotate(i, 2);

	return 0;
}