#define _CRT_SECURE_NO_WARNINGS
#include "list.h"
#include <stdio.h>

Item* ListLoad(const char* filename) {
	FILE* f = fopen(filename, "r");
	Item* l = ListCreateEmpty();
	if (f == NULL)
		return l;
	ElemType e, elem;
	while ((elem = ElemRead(f, &e)) > 0) {
		l = ListInsertHead(&e, l);
	}
	fclose(f);
	return l;
}