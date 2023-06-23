#include <stdlib.h>

int TempoTrasporto(int n, const int* t, int p) {
	int* persone_per_citta = calloc(n, sizeof(int));
	persone_per_citta[0] = p;
	int minuti = 0;
	int i = 0;
	while (persone_per_citta[n - 1] != p) {
		if (i > n)
			--i;
		for (; i <= n; ++i) {
			for (int j = i; j >=0 ; --j) {
				if (j == n)
					j -= 2;
				if (j == n - 1)
					--j;
				if (persone_per_citta[j] > 0) {
					if (persone_per_citta[j] > t[j]) {
						persone_per_citta[j] -= t[j];
						persone_per_citta[j + 1] += t[j];
					}
					else {
						persone_per_citta[j + 1] += persone_per_citta[j];
						persone_per_citta[j] = 0;
					}
				}
			}
			++minuti;
		}
	}
	free(persone_per_citta);
	return minuti;
}