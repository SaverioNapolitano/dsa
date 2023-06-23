#include "list.h"
#include <string.h>
Item* Delete(Item* i, const char* name) {

	if (ListIsEmpty(i))
		return i;
	Item* segnaposto = NULL;
	Item* prev = NULL;
	for (Item* tmp = i; !ListIsEmpty(tmp); tmp = ListGetTail(tmp)) {
		if (strcmp(ListGetHeadValue(tmp)->name, name) == 0) {
			segnaposto = tmp->next;
			tmp->next = NULL;
			ListDelete(tmp);
			prev->next = segnaposto;
			break;
		}
		prev = tmp;
	}
	

	return i;
}