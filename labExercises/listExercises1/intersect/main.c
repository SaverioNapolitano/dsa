#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include "list.h"

extern Item* Intersect(const Item* i1, const Item* i2);

Item* ListLoad(const char* filename) {
	FILE* f = fopen(filename, "r");
	Item* l = ListCreateEmpty();
	if (f == NULL)
		return l;
	ElemType e;
	ElemType elem = ElemRead(f, &e);
	if (elem <= 0)
		return l;
	l = ListInsertHead(&e, l);
	while ((elem = ElemRead(f, &e)) > 0) {
		l = ListInsertHead(&e, l);
	}
	fclose(f);
	return l;
}

int main(void) {
	char s1[] = "data_00.txt";
	char s2[] = "data_01.txt";
	Item* i1 = ListLoad(s1);
	Item* i2 = ListLoad(s2);

	Item* ret = Intersect(i1, i2);

	return EXIT_SUCCESS;
}