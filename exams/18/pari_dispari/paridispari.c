#include "list.h"
#include <stdlib.h>

Item* PariDispari(Item* i) {

	if (ListIsEmpty(i)) {
		return NULL;
	}

	Item* prev = NULL;
	Item* tmp_prev = NULL;
	Item* new_head = i;
	Item* tmp = NULL;
	Item* dispari = NULL;

	while (!ListIsEmpty(i)) {
		prev = i;
		if (prev->value % 2 == 0) {
			tmp = new_head;
			new_head = prev;
			tmp_prev = prev->next;
			if (dispari != NULL) {
				prev->next = dispari;
				dispari->next = tmp_prev;
			}
			if (prev->next != tmp_prev) {
				new_head->next = tmp;
			}
			else {
				new_head = tmp;
			}
			i = tmp_prev;
		}
		else {
			dispari = i;
			i = ListGetTail(i);
		}
	}
	return new_head;
}