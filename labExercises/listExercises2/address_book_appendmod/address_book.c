#include "list.h"

Item* AppendMod(Item* i1, Item* i2) {

	Item fake_head = { .next = i1 };
	/*if (ListIsEmpty(i1))
		return i2;

	Item* head = i1;*/
	Item* prev = &fake_head;
	for (; !ListIsEmpty(i1); i1 = ListGetTail(i1)) {
		prev = i1;
	}
	prev->next = i2;

	return fake_head.next;
}