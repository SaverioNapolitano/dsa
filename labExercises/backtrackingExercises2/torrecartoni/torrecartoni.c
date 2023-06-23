#include "torrecartoni.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

static void TorreCartoniRec(const Cartone* c, size_t n, size_t i, int* vcurr, unsigned int peso_attuale, unsigned int h_parz, bool* pacchi_presi, int* best, unsigned int* best_h, int size, int *dim)
{
	if (i == n) {
		if (h_parz > *best_h) {
			*best_h = h_parz;
			memcpy(best, vcurr, size * sizeof(int));
			*dim = size;
		}
		return;
	}
	bool caricati = false;
	for (size_t j = 0; j < n; j++) {
		if (pacchi_presi[j] == false) {
			if (peso_attuale <= c[j].l) {
				pacchi_presi[j] = true;
				vcurr[i] = j;
				caricati = true;
				TorreCartoniRec(c, n, i + 1, vcurr, peso_attuale + c[j].p, h_parz + c[j].a, pacchi_presi, best, best_h, size + 1, dim);
				pacchi_presi[j] = false;
			}
		}
	}
	if(!caricati)
		TorreCartoniRec(c, n, n, vcurr, peso_attuale, h_parz, pacchi_presi, best, best_h, size, dim);
	//tiro alla fune: permuto il primo insieme in tutti i modi possibili e facendo somma_insieme - (somma_totale - somma_insieme) trovo la best
}
void TorreCartoni(const Cartone* c, size_t n)
{
	int* vcurr = malloc((n) * sizeof(int));

	bool* pacchi_presi = calloc(n, sizeof(bool));

	int* best = malloc((n) * sizeof(int));
	unsigned int best_h = 0;
	int dim = 0;
	TorreCartoniRec(c, n, 0, vcurr, 0, 0, pacchi_presi, best, &best_h, 0, &dim);

	for (int i = 0; i < dim; ++i) {
			printf("%i\n", best[i]);
	}

	printf("Altezza: %i cm", best_h);

	free(vcurr);
	free(pacchi_presi);
	free(best);
}