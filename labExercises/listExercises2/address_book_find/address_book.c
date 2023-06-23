#include "list.h"
#include <string.h>
const ElemType* Find(const Item* i, const char* name) {
	const ElemType* r = NULL;
	for (const Item* tmp = i; !ListIsEmpty(tmp); tmp = ListGetTail(tmp)) {
		if (strcmp(ListGetHeadValue(tmp)->name, name) == 0) {
			r = ListGetHeadValue(tmp);
			break;
		}
	}
	return r;
}