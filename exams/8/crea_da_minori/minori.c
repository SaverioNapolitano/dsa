#include "list.h"

Item* CreaDaMinori(const Item* i, int v) {
	if (ListIsEmpty(i))
		return NULL;
	Item* ret = ListCreateEmpty();
	ElemType e = v;
	for (const Item* tmp = i; !ListIsEmpty(tmp); tmp = ListGetTail(tmp)) {
		if (ElemCompare(&e, ListGetHeadValue(tmp)) >= 0) {
			ret = ListInsertBack(ret, ListGetHeadValue(tmp));
		}
	}
	return ret;
}