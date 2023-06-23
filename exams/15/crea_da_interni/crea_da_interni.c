#include "list.h"
#include <math.h>
Item* CreaDaInterni(const Item* i, double r) {
	Item* ret = ListCreateEmpty();

	for (const Item* tmp = i; !ListIsEmpty(tmp); tmp = ListGetTail(tmp)) {
		if (sqrt(pow(tmp->value.x, 2) + pow(tmp->value.y, 2)) < r) {
			ret = ListInsertBack(ret, &tmp->value);
		}
	}

	return ret;
}