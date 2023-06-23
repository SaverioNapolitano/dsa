#include "list.h"

extern Item* Sum(const Item* i1, const Item* i2);

int main(void) {
	ElemType v[] = { 7 };
	size_t size = sizeof(v) / sizeof(ElemType);
	Item* i1 = ListCreateEmpty();
	for (size_t j = 0; j < size; ++j) {
		i1 = ListInsertBack(i1, v + j);
	}
	ElemType v2[] = { 3, 2, 4 };
	size_t size2 = sizeof(v2) / sizeof(ElemType);
	Item* i2 = ListCreateEmpty();
	for (size_t j = 0; j < size2; ++j) {
		i2 = ListInsertBack(i2, v2+ j);
	}
	Item* ret = ListCreateEmpty();
	ret = Sum(i1, i2);

	return 0;
}