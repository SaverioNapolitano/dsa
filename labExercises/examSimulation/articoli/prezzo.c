#include "prezzo.h"
#include <stdbool.h>
#include <stdio.h>
static void TrovaArticoliRec(const struct Articolo* a, size_t a_size, int sum, bool* preso, size_t i, struct Articolo *sol) {

	if (i == a_size) {
		int somma = 0;
		for (size_t j = 0; j < a_size; ++j) {
			if (preso[j]) {
				somma += a[j].prezzo;
			}
		}
		if (somma != sum)
			return;
		size_t k = 0;
		for (size_t j = 0; j < a_size; ++j) {
			if (preso[j]) {
				sol[k] = a[j];
				++k;
			}
		};
		size_t l = 0;
		if (k == 1) {
			printf("%s,\n", sol[l].nome);
			return;
		}
		for (; l < k - 1; ++l) {
			printf("%s, ", sol[l].nome);
		}
		if (l != 0) {
			printf("%s,\n", sol[l].nome);
		}
		return;
	}

	preso[i] = 0;
	TrovaArticoliRec(a, a_size, sum, preso, i+1, sol);

	preso[i] = 1;
	TrovaArticoliRec(a, a_size, sum, preso, i+1, sol);
}
void TrovaArticoli(const struct Articolo* a, size_t a_size, int sum) {
	if (a == NULL)
		return;
	bool* preso = calloc(a_size, sizeof(bool));
	struct Articolo* sol = calloc(a_size, sizeof(struct Articolo));
	TrovaArticoliRec(a, a_size, sum, preso, 0, sol);
	free(preso);
	free(sol);
	return;
}