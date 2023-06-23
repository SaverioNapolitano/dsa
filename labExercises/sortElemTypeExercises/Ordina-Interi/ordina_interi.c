#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include "elemtype.h"
typedef struct {
	size_t capacity;
	size_t size;
	ElemType* data;
} Vector;
void Ordina(Vector* v, ElemType* a) {
	int i;
	for (i = v->size - 1; i >= 0 && v->data[i] > *a; --i) {
		v->data[i + 1] = v->data[i];
	}
	v->data[i + 1] = *a;
}
Vector* VectorReadSorted(FILE *f) {

	Vector* new = malloc(sizeof(Vector));
	new->capacity = 1;
	new->size = 0;
	new->data = malloc(sizeof(ElemType));
	ElemType a, b;

	while ((b = ElemRead(f, &a)) != EOF) {
		if (new->size == new->capacity) {
			new->capacity *= 2;
			new->data = realloc(new->data, new->capacity * sizeof(ElemType));
		}
		Ordina(new, &a);
		new->size++;
	}
	new->data = realloc(new->data, new->size * sizeof(ElemType));

	return new;
}
int main(int argc, char** argv) {

	if (argc != 3) {
		fprintf(stderr, "Troppi parametri");
		return 2;
	}
	if (argv[1] == NULL)
		return 1;

	FILE* f = fopen(argv[1], "r");
	if (f == NULL)
		return 1;

	Vector* v = VectorReadSorted(f);

	FILE* o = fopen(argv[2], "w");
	if (o == NULL)
		return 1;

	for (size_t i = 0; i < v->size; ++i) {
		ElemWrite(&v->data[i], o);
		fprintf(o, "\n");
	}

	free(v->data);
	free(v);
	fclose(f);
	fclose(o);
	return 0;
}