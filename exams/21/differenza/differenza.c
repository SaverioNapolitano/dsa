#include "differenza.h"

Item* Differenza(const Item* i1, const Item* i2) {
	Item* diff = ListCreateEmpty();
	if (ListIsEmpty(i2) && ListIsEmpty(i1))
		return diff;
	if (ListIsEmpty(i2)) {
		for (const Item* tmp = i1; !ListIsEmpty(tmp); tmp = ListGetTail(tmp)) {
			diff = ListInsertBack(diff, ListGetHeadValue(tmp));
		}
		
		return diff;
	}
	ElemType p = 0;
	ElemType s = 0;
	ElemType m = 0;
	ElemType r = 0;
	for (const Item* tmp1 = i1, *tmp2 = i2; !ListIsEmpty(tmp1); tmp1 = ListGetTail(tmp1), tmp2 = ListGetTail(tmp2)) {
		s = *ListGetHeadValue(tmp1);
		s -= p;
		p = 0;
		if (ListIsEmpty(tmp2)) {
			m = 48;
		}
		else {
			m = *ListGetHeadValue(tmp2);
		}
		if (s < m) {
			p = 1;
			s += 10;
		}
		r = s - m + 48;
		diff = ListInsertBack(diff, &r);
		if (m == 48)
			break;
	}
	return diff;

}