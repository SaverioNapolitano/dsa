#include "list.h"

Item* Sort(Item* i) {
	Item* tmp_a = i;
	while (!ListIsEmpty(tmp_a)) {
		Item* tmp_b = ListGetTail(tmp_a);
		while (!ListIsEmpty(tmp_b)) {
			if(ElemCompare(ListGetHeadValue(tmp_a), ListGetHeadValue(tmp_b)) > 0) {
				ElemSwap(&tmp_a->value, &tmp_b->value);
			}
			tmp_b = ListGetTail(tmp_b);
		}
		tmp_a = ListGetTail(tmp_a);
	}

	return i;
}