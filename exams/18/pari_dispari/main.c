#include "list.h"

extern Item* PariDispari(Item* i);

int main() {
	ElemType v[] = { 4, 8, 0, 10, 2, 14, 200, 78, 1, 3, 7, 5, 9 };
	Item* i = ListCreateEmpty();

	for (size_t j = 0; j < 13; ++j) {
		i = ListInsertBack(i, v + j);
	}

	Item* l = PariDispari(i);

	return 0;
}