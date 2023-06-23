#include <stdlib.h>
#include <float.h>
#include <math.h>
#include <stdbool.h>
#include "sciatori.h"

void Ordina(double* altezze, double* lunghezze, size_t v_size) {
	for (size_t i = 0; i < v_size; ++i) {
		double differenza = DBL_MAX;
		for (size_t j = i; j < v_size; ++j) {
			if (fabs(altezze[i] - lunghezze[j]) < differenza) {
				differenza = fabs(altezze[i] - lunghezze[j]);
				double tmp = lunghezze[i];
				lunghezze[i] = lunghezze[j];
				lunghezze[j] = tmp;
			}
		}
	}
}
Sciatore* Accoppia(double* altezze, double* lunghezze, size_t v_size) {
	if (v_size == 0)
		return NULL;
	Sciatore* res = malloc(v_size * sizeof(Sciatore));
	Ordina(altezze, lunghezze, v_size);
	for (size_t k = 0; k < v_size; ++k) {
		res[k].a = altezze[k];
		res[k].l = lunghezze[k];
	}
	return res;
}