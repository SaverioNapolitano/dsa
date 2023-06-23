#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include "gioielli.h"

int CompareGioielli(const void* a, const void* b) {

	const Gioiello* pa = (const Gioiello*)a;
	const Gioiello* pb = b;
	float a_value = pa->peso / pa->prezzo;
	float b_value = pb->peso / pb->prezzo;

	return (a_value < b_value) - (a_value > b_value);

}
Gioiello* CompraGioielli(const char* filename, float budget, size_t* ret_size) {

	FILE* f = fopen(filename, "r");

	if (f == NULL)
		return NULL;

	size_t dim = 1;
	Gioiello* v = malloc(dim*sizeof(Gioiello));
	++dim;
	size_t size = 0;
	int e;
	while ((e = fscanf(f, "%i%f%f", &v[size].codice, &v[size].peso, &v[size].prezzo))!=EOF) {
		++size;
		v = realloc(v, (++dim) * sizeof(Gioiello));
	}
	v = realloc(v, size * sizeof(Gioiello));
	float* scelta = malloc(size * sizeof(float));
	qsort(v, size, sizeof(Gioiello), CompareGioielli);
	for (size_t i = 0; i < size; ++i) {
		scelta[i] = v[i].peso / v[i].prezzo;
	}
	Gioiello * res = malloc(size * sizeof(Gioiello));
	size_t res_size = 0;
	for (size_t j = 0; j < size && budget != 0; ++j) {
		if (v[j].prezzo <= budget) {
			res[res_size] = v[j];
			budget -= v[j].prezzo;
			++res_size;
		}
	}
	*ret_size = res_size;
	res = realloc(res, res_size * sizeof(Gioiello));
	fclose(f);
	free(v);
	free(scelta);
	return res;

}