#include "list.h"

Item* Append(const Item* i1, const Item* i2) {

	Item* l1 = ListCreateEmpty();

	for (const Item* tmp1 = i1; !ListIsEmpty(tmp1); tmp1 = ListGetTail(tmp1)) {
		l1 = ListInsertBack(l1, ListGetHeadValue(tmp1));
	}
	for (const Item* tmp2 = i2; !ListIsEmpty(tmp2); tmp2 = ListGetTail(tmp2)) {
		l1 = ListInsertBack(l1, ListGetHeadValue(tmp2));
	}

	return l1;
}