#include "list.h"
#include <stdbool.h>
int ContaVette(const Item* i) {
	int vette = 0;
	if (ListIsEmpty(i))
		return vette;
	for (const Item* tmp = i; !ListIsEmpty(tmp); tmp = ListGetTail(tmp)) {
		bool vetta = true;
		for (const Item* tmp1 = tmp->next; !ListIsEmpty(tmp1); tmp1 = ListGetTail(tmp1)) {
			if (*ListGetHeadValue(tmp) <= *ListGetHeadValue(tmp1)) {
				vetta = false;
				break;
			}
		}
		if (vetta)
			vette++;
	}
	return vette;
}