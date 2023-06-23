#include "remove.h"

Item* RemoveDuplicates(Item* i) {
	if (i == NULL)
		return NULL;
	Item* head = i;
	for (Item* tmp = i->next; !ListIsEmpty(tmp); tmp = ListGetTail(tmp)) {
		if (ElemCompare(ListGetHeadValue(head), ListGetHeadValue(tmp)) == 0) {
			head->next = tmp->next;
			tmp->next = NULL;
			ListDelete(tmp);
			tmp = head;
		}
		else {
			head = head->next;
		}
	}
	return i;
}