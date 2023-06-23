#include "list.h"

Item* Reverse(Item* i) {

	if (i == NULL)
		return NULL;

	Item* prev = NULL;
	Item* succ = NULL;
	Item* tmp_prev = NULL;
	Item* tmp = NULL;
	Item* new_head = NULL;
	while (1) {
		if (i != NULL) {
			prev = i;
			succ = ListGetTail(i);
		}
		if (succ != NULL) {
			i = succ->next;
		}
		else {
			i = succ;
			prev->next = new_head;
			new_head = prev;
			break;
		}
		succ->next = prev;
		tmp_prev = prev->next;
		prev->next = tmp;
		tmp = tmp_prev;
		new_head = succ;
		if (i == NULL)
			break;
	}
	return new_head;
}