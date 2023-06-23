#include "list.h"

Item* Rotate(Item* i, int n) {

	Item* new_head = NULL;
	int count = 0;
	Item* old_head = i;
	for (; !ListIsEmpty(i); i = ListGetTail(i)) {
		if (count == n) {
			new_head = i;
		}
		++count;
		if (i->next == NULL) {
			i->next = old_head;
			for (int j = 0; j < n-1; ++j) {
				old_head = ListGetTail(old_head);
			}
			old_head->next = NULL;
			break;
		}
	}
	i = new_head;
	return i;
}