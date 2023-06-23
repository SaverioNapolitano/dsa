#include "list.h"

Item* Reverse(const Item* i) {
	Item* l = ListCreateEmpty();

	for (const Item* tmp = i; !ListIsEmpty(tmp); tmp = ListGetTail(tmp))
		l = ListInsertHead(ListGetHeadValue(tmp), l);
	
	return l;
}