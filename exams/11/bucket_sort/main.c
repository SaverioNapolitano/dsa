#include "list.h"

extern Item* BucketSort(Item* l);

int main(void) {
	ElemType v[] = { 7, 2, 5, 4 };
	Item* l = ListCreateEmpty();
	size_t size = sizeof(v) / sizeof(ElemType);
	for (size_t i = 0; i < size; ++i) {
		l = ListInsertBack(l, v + i);
	}
	Item* r = ListCreateEmpty();
	r = BucketSort(l);
}