#include "list.h"
#include <stdbool.h>
Item* IntersectNoRep(const Item* i1, const Item* i2) {
	Item* l = ListCreateEmpty();
	for (const Item* tmp1 = i1; !ListIsEmpty(tmp1); tmp1 = ListGetTail(tmp1)) {
		bool preso = false;
		for (const Item* tmp2 = i2; !ListIsEmpty(tmp2); tmp2 = ListGetTail(tmp2)) {
			if (ElemCompare(ListGetHeadValue(tmp1), ListGetHeadValue(tmp2)) == 0) {
				for (const Item* tmp3 = l; !ListIsEmpty(tmp3); tmp3 = ListGetTail(tmp3)) {
					if (ElemCompare(ListGetHeadValue(tmp3), ListGetHeadValue(tmp1)) == 0) {
						preso = true;
						break;
					}
				}
				if (!preso) {
					l = ListInsertBack(l, ListGetHeadValue(tmp1));
					break;
				}
			}
		}
	}

	return l;
}
Item* DiffNoRep(const Item* i1, const Item* i2) {
	Item* l = ListCreateEmpty();
	for (const Item* tmp1 = i1; !ListIsEmpty(tmp1); tmp1 = ListGetTail(tmp1)) {
		bool preso = false;
		bool presente = false;
		for (const Item* tmp2 = i2; !ListIsEmpty(tmp2); tmp2 = ListGetTail(tmp2)) {
			if (ElemCompare(ListGetHeadValue(tmp1), ListGetHeadValue(tmp2)) == 0) {
				presente = true;
				break;
			}
		}
		if (!presente) {
			for (const Item* tmp3 = l; !ListIsEmpty(tmp3); tmp3 = ListGetTail(tmp3)) {
				if (ElemCompare(ListGetHeadValue(tmp3), ListGetHeadValue(tmp1)) == 0) {
					preso = true;
					break;
				}
			}
			if(!preso)
				l = ListInsertBack(l, ListGetHeadValue(tmp1));
		}
	}

	return l;
}