#include "list.h"

Item* ConcatenaN(Item** v, size_t v_size) {

	Item* l = ListCreateEmpty();

	if (v_size == 0)
		return l;

	bool invalid = true;
	Item* head = NULL;
	for (size_t i = 0; i < v_size; ++i) {
		if (v[i] != NULL) {
			invalid = false;
			head = v[i];
			break;
		}
	}
	if (invalid)
		return l;

	size_t j = 0;
	Item* prev = NULL;
	while (j<v_size) {

		for (Item* tmp = v[j]; !ListIsEmpty(tmp); tmp = ListGetTail(tmp)) {
			prev = tmp;
		}
		if (v[j + 1] != NULL) {
			if(prev!=NULL)
				prev->next = v[j + 1];
			else
				prev = v[j + 1];
		}
		++j;
	}
	prev->next = NULL;
	prev = head;

	return prev;
		
}