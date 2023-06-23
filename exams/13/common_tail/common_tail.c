#include "list.h"
#include <stdlib.h>
const Item* CommonTail(const Item* i1, const Item* i2) {
	const Item* tmp1 = i1;
	for (; !ListIsEmpty(tmp1); tmp1 = ListGetTail(tmp1)) {
		for (const Item* tmp2 = i2; !ListIsEmpty(tmp2); tmp2 = ListGetTail(tmp2)) {
			if (tmp1 == tmp2) {
				return tmp1;
			}
		}
	}
	return NULL;
}