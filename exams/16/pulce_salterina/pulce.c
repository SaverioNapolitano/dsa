#include <stdlib.h>
#include <string.h>
static void GuidaLaPulceRec(const int* f, size_t f_size, int a, int b, int n, int h, size_t* ret_size, char* solcurr, int i, int p, size_t count, char*bsol) {

	if (p < 0)
		return;

	for (size_t j = 0; j < f_size; ++j) {
		if (p == f[j])
			return;
	}
	
	if (solcurr[i - 1] == 'b') {
		if (solcurr[i - 2] == 'b')
			return;
	}

	if (p == h) {
		if (count < *ret_size) {
			memcpy(bsol, solcurr, count * sizeof(char));
			*ret_size = count;
		}
		return;
	}

	if (i == n)
		return;

	solcurr[i] = 'a';
	GuidaLaPulceRec(f, f_size, a, b, n, h, ret_size, solcurr, i + 1, p + a, count + 1, bsol);
	solcurr[i] = 0;

	solcurr[i] = 'b';
	GuidaLaPulceRec(f, f_size, a, b, n, h, ret_size, solcurr, i + 1, p - b, count + 1, bsol);
	solcurr[i] = 0;
}
char* GuidaLaPulce(const int* f, size_t f_size, int a, int b, int n, int h, size_t* ret_size) {
	char* solcurr = calloc(n, sizeof(char));
	char* bsol = calloc(n, sizeof(char));
	*ret_size = (size_t)n+1;
	GuidaLaPulceRec(f, f_size, a, b, n, h, ret_size, solcurr, 0, 0, 0, bsol);
	if (*ret_size == (size_t)n + 1) {
		free(bsol);
		free(solcurr);
		*ret_size = 0;
		return NULL;
	}
	free(solcurr);
	bsol = realloc(bsol, *ret_size * sizeof(char));
	return bsol;
}