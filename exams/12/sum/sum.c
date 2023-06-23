#include "list.h"

Item* Sum(const Item* i1, const Item* i2) {
	Item* r = ListCreateEmpty();
	if (ListIsEmpty(i1) && ListIsEmpty(i2))
		return r;
	if (ListIsEmpty(i1) && !ListIsEmpty(i2)) {
		for (const Item* tmp = i2; !ListIsEmpty(tmp); tmp = ListGetTail(tmp)) {
			r = ListInsertBack(r, ListGetHeadValue(tmp));
		}
		return r;
	}
	if (!ListIsEmpty(i1) && ListIsEmpty(i2)) {
		for (const Item* tmp = i1; !ListIsEmpty(tmp); tmp = ListGetTail(tmp)) {
			r = ListInsertBack(r, ListGetHeadValue(tmp));
		}
		return r;
	}
	ElemType resto = 0;
	bool insert = false;
	for (const Item* tmp1 = i1, *tmp2 = i2; !ListIsEmpty(tmp1) || !ListIsEmpty(tmp2);) {
		insert = false;
		if (ListIsEmpty(tmp1)) {
			if (resto == 1) {
				ElemType e = 1 + *ListGetHeadValue(tmp2);
				resto = 0;
				if (e >= 10) {
					e -= 10;
					resto++;
				}
				r = ListInsertBack(r, &e);
			}
			else {
				r = ListInsertBack(r, ListGetHeadValue(tmp2));
			}
			insert = true;
		}
		if (ListIsEmpty(tmp2)) {
			if (resto == 1) {
				ElemType e = 1 + *ListGetHeadValue(tmp1);
				resto = 0;
				if (e >= 10) {
					e -= 10;
					resto++;
				}
				r = ListInsertBack(r, &e);
			}
			else {
				r = ListInsertBack(r, ListGetHeadValue(tmp1));
			}
			insert = true;
		}
		if(!insert) {
			ElemType e = *ListGetHeadValue(tmp1) + *ListGetHeadValue(tmp2);
			if (resto == 1) {
				resto = 0;
				e++;
			}
			if (e >= 10) {
				e -= 10;
				resto++;
			}
			r = ListInsertBack(r, &e);
		}
		if (!ListIsEmpty(tmp1)) {
			tmp1 = ListGetTail(tmp1);
		}
		if (!ListIsEmpty(tmp2)) {
			tmp2 = ListGetTail(tmp2);
		}
	}
	if (resto == 1) {
		ElemType e = 1;
		r = ListInsertBack(r, &e);
	}
	return r;
}