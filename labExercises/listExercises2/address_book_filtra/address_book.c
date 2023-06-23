#include "list.h"
#include <string.h>
Item* Filtra(const Item* i, const char* city) {
	Item* l = ListCreateEmpty();

	for (const Item* tmp = i; !ListIsEmpty(tmp); tmp = ListGetTail(tmp)) {
		if (strcmp(ListGetHeadValue(tmp)->city, city) == 0)
			l = ListInsertBack(l, ListGetHeadValue(tmp));
	}

	return l;
}