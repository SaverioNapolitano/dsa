#include "list.h"

Item* CopiaDaN(const Item* i, int n) {
	if (ListIsEmpty(i))
		return NULL;
	int size = 0;
	for (const Item* tmp = i; !ListIsEmpty(tmp); tmp = ListGetTail(tmp)) {
		size++;
	}
	if (size < n)
		return NULL;
	int j = 0;
	Item* ret = ListCreateEmpty();
	for (const Item* tmp = i; !ListIsEmpty(tmp); tmp = ListGetTail(tmp)) {
		++j;
		if (j >= n) {
			ret = ListInsertBack(ret, ListGetHeadValue(tmp));
		}
	}
	return ret;
}