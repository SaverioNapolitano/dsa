#define _CRT_SECURE_NO_WARNINGS
#include "vettore.h"
#include <stdio.h>
#include <stdlib.h>
Vector* VectorRead(const char* filename) {
	if (filename == NULL)
		return NULL;
	FILE* f = fopen(filename, "r");
	if (f == NULL)
		return NULL;
	
	Vector* new = malloc(sizeof(Vector));
	new->capacity = 1;
	new->size = 0;
	new->data = malloc(sizeof(ElemType));
	ElemType e;

	while ((e = ElemRead(f, &new->data[new->size]))!=EOF) {
		new->size++;
		if (new->size == new->capacity) {
			new->capacity *= 2;
			new->data = realloc(new->data, new->capacity * sizeof(ElemType));
		}
	}
	new->data = realloc(new->data, new->size * sizeof(ElemType));

	fclose(f);
	return new;
}

void Ordina(Vector* v, ElemType* a) {
	int i;
	for (i = v->size - 1; i >= 0 && v->data[i] > *a; --i) {
		v->data[i + 1] = v->data[i];
	}
	v->data[i + 1] = *a;
}
Vector* VectorReadSorted(const char* filename) {

	if (filename == NULL)
		return NULL;
	FILE* f = fopen(filename, "r");
	if (f == NULL)
		return NULL;

	Vector* new = malloc(sizeof(Vector));
	new->capacity = 1;
	new->size = 0;
	new->data = malloc(sizeof(ElemType));
	ElemType a, b;

	while ((b=ElemRead(f, &a))!=EOF) {
		if (new->size == new->capacity) {
			new->capacity *= 2;
			new->data = realloc(new->data, new->capacity*sizeof(ElemType));
		}
		Ordina(new, &a);
		new->size++;
	}
	new->data = realloc(new->data,new->size * sizeof(ElemType));

	fclose(f);
	return new;
}