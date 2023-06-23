#include "list.h"

Item* ElementiPari(const Item* i) {
	Item* res = ListCreateEmpty();
	if (ListIsEmpty(i))
		return res;
	size_t count = 0;
	for (const Item* tmp = i; !ListIsEmpty(tmp); tmp = ListGetTail(tmp)) {
		if (count % 2 == 0)
			res = ListInsertBack(res, ListGetHeadValue(tmp));
		++count;
	}
	return res;
}