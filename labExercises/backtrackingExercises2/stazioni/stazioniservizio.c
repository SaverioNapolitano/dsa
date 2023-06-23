#include <stdlib.h>
#include <stdio.h>
#include <float.h>
#include <string.h>
static void StazioniServizioRec(double m, const double* d, const double* p, size_t n, size_t i, int *vcurr, double carburante, double mp, double costo, double *b_costo, int* b_sol, size_t j) {
	if (i == n) {
		if (mp != m) {
			if (carburante >= 0.05 * (m - mp)) {
				if (costo < *b_costo) {
					memcpy(b_sol, vcurr, n * sizeof(int));
					*b_costo = costo;
					return;
				}
			}
			else {
				return;
			}
		}
		if (costo < *b_costo) {
			memcpy(b_sol, vcurr, n * sizeof(int));
			*b_costo = costo;
			return;
		}
	}
	double consumo;
	double prezzo;
	for (; j < n; ++j) {
		if (j<n-1 && carburante > 0.05 * (d[j]+d[j+1])) {
			vcurr[i] = -1;
			consumo = 0.05 * d[j];
			prezzo = 0;
		}
		else {
			vcurr[i] = j;
			consumo = carburante - 30;
			prezzo = (30-carburante+0.05*d[j]) * p[j];
		}
		if (j == 0) {
			vcurr[i] = j;
			consumo = 0;
			prezzo = 0.05 * d[j] * p[j];
		}
		if (j == n - 1) {
			if (carburante > 0.05 * (m - mp)) {
				vcurr[i] = -1;
				consumo = 0.05 * d[j];
				prezzo = 0;
			}
			else {
				vcurr[i] = j;
				consumo = carburante - 30;
				prezzo = (30 - carburante + 0.05 * d[j]) * p[j];
			}
		}
		StazioniServizioRec(m, d, p, n, i + 1, vcurr, carburante - consumo, mp + d[j], costo + prezzo, b_costo, b_sol, j + 1);
	}
}
void StazioniServizio(double m, const double* d, const double* p, size_t n) {
	int* vcurr = malloc(n * sizeof(int));
	int* b_sol = malloc(n * sizeof(int));
	double b_costo = DBL_MAX;
	StazioniServizioRec(m, d, p, n, 0, vcurr, 30, 0, 0, &b_costo, b_sol, 0);
	if (b_costo == DBL_MAX) {
		printf("Non esistono soluzioni");
	}
	else {
		for (size_t j = 0; j < n; ++j) {
			if (b_sol[j] != -1)
				printf("%d ", b_sol[j]);
		}
		printf("\nSpesa totale: %f euro", b_costo);
	}

	free(b_sol);
	free(vcurr);
	return;
}