#include "list.h"

extern Item* Reverse(Item* i);

int main(void) {
	ElemType v[] = { 1, 3, 4, 7, 8, -2 };
	Item* i = ListCreateEmpty();
	for (size_t j = 0; j < 6; ++j) {
		i = ListInsertBack(i, v + j);
	}
	Item* l = ListCreateEmpty();
	l = Reverse(i);


	return 0;
}