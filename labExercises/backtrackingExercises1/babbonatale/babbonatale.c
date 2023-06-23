#include <stdlib.h>
#include <stdio.h>
struct soluzione
{
	int* vsol;
	int dim;
	size_t n_pacchi;
};
static void BabboNataleRec(const int* pacchi, size_t pacchi_size, int p, size_t i, int* vcurr, int* nsol, struct soluzione* sol, int somma, size_t count) {
	if (somma > p)
		return;
	if (count + pacchi_size - i <= sol->n_pacchi)
		return;
	if (i == pacchi_size) {
			sol->n_pacchi = count;
			for (size_t j = 0; j < pacchi_size; ++j) {
				sol->vsol[j] = vcurr[j];
			}
		return;
	}
	vcurr[i] = 0;
	BabboNataleRec(pacchi, pacchi_size, p, i + 1, vcurr, nsol, sol, somma, count);

	vcurr[i] = 1;
	BabboNataleRec(pacchi, pacchi_size, p, i + 1, vcurr, nsol, sol, somma + pacchi[i], count + 1);
}

void BabboNatale(const int* pacchi, size_t pacchi_size, int p) {

	int* vcurr = malloc(sizeof(int) * pacchi_size);
	struct soluzione* sol = malloc(sizeof(struct soluzione));
	sol->vsol = malloc(sizeof(int) * pacchi_size);
	sol->dim = pacchi_size;
	sol->n_pacchi = 0;
	int nsol = 0;
	BabboNataleRec(pacchi, pacchi_size, p, 0, vcurr, &nsol, sol, 0, 0);
	for (int j = 0; j < sol->dim; ++j) {
		printf("%d ", sol->vsol[j]);
	}
	free(sol->vsol);
	free(sol);
	free(vcurr);
}