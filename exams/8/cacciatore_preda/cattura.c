#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <stdbool.h>
static void CacciatorePredaRec(const char* v, size_t v_size, int u, int* sol, int *p, size_t i, int *bsol) {

	if (i > 0) {
		if ((v[i - 1] == 'C' || v[i - 1] == 'c') && sol[i - 1] == -2) 
			return;
		if ((v[i - 1] == 'P' || v[i - 1] == 'p') && sol[i - 1] >= 0) 
			return;
		if ((v[i - 1] == 'C' || v[i - 1] == 'c') && (v[sol[i - 1]] == 'C' || v[sol[i - 1]] == 'c')) 
			return;
		if ((v[i - 1] == 'C' || v[i - 1] == 'c') && (v[sol[i - 1]] == 'P' || v[sol[i - 1]] == 'p')) {
			if (abs((int)i - 1 - sol[i - 1]) > u)
				return;
		}

	}
	if (i == v_size) {
		int pcurr = 0;
		int pcatt = 0;
		for (size_t k = 0; k < i; ++k) {
			if (sol[k] >= 0) {
				pcurr++;
				for (size_t a = 0; a < i; ++a) {
					if (a == k)
						continue;
					if (sol[a] == sol[k])
						return;
				}
			}
			if (sol[k] == -2)
				pcatt++;
		}
		if (pcurr != pcatt)
			return;

		if (pcurr > *p) {
			*p = pcurr;
			memcpy(bsol, sol, i * sizeof(int));
		}
		return;
	}

	for (int j = -2; j < (int)v_size; ++j) {
		sol[i] = j;
		CacciatorePredaRec(v, v_size, u, sol, p, i + 1, bsol);
	}
}
int* CacciatorePreda(const char* v, size_t v_size, int u) {
	int* bsol = malloc(v_size * sizeof(int));
	bool no_prede = true;
	bool no_cacciatori = true;
	for (size_t x = 0; x < v_size; ++x) {
		if (!no_prede && !no_cacciatori)
			break;
		if (v[x] == 'P' || v[x] == 'p')
			no_prede = false;
		if (v[x] == 'C' || v[x] == 'c')
			no_cacciatori = false;
	}
	if (no_prede || no_cacciatori) {
		memset(bsol, -1, v_size * sizeof(int));
		return bsol;
	}
	int* sol = malloc(v_size * sizeof(int));
	int p = 0;
	CacciatorePredaRec(v, v_size, u, sol, &p, 0, bsol);
	free(sol);
	return bsol;
}