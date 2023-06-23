#include "list.h"

extern Item* ElementiPari(const Item* i);

int main(void) {
	ElemType v[] = { 7, 2, 5, 8, 6 };
	size_t size = sizeof(v) / sizeof(ElemType);
	Item* i = ListCreateEmpty();
	for (size_t j = 0; j < size; ++j) {
		i = ListInsertBack(i, v + j);
	}
	Item* a = ListCreateEmpty();
	a = ElementiPari(i);

	return 0;
}