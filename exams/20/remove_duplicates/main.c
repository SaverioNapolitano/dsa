#include "remove.h"

int main(void) {

	ElemType v[] = { 1, 1, 1, 2, 2, 3 };
	size_t size = sizeof(v) / sizeof(ElemType);
	Item* i = NULL;
	for (size_t j = 0; j < size; ++j) {
		i = ListInsertBack(i, v + j);
	}
	Item* r = RemoveDuplicates(i);


	return 0;
}