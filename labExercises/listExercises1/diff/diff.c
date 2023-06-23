#include "list.h"
#include <stdbool.h>
Item* Diff(const Item* i1, const Item* i2) {
	Item* l = ListCreateEmpty();
	for (const Item* tmp1 = i1; !ListIsEmpty(tmp1); tmp1 = ListGetTail(tmp1)) {
		bool presente = false;
		for (const Item* tmp2 = i2; !ListIsEmpty(tmp2); tmp2 = ListGetTail(tmp2)) {
			if (ElemCompare(ListGetHeadValue(tmp1), ListGetHeadValue(tmp2)) == 0) {
				presente = true;
				break;
			}
		}
		if (!presente)
			l = ListInsertBack(l, ListGetHeadValue(tmp1));
	}

	return l;
}