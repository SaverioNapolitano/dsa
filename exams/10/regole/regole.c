#include <stdio.h>
#include <string.h>
#include <stdlib.h>
static void RegoleRec(const char* r, size_t n, size_t i, int *sol) {

	if (i == n + 1) {
		for (size_t a = 0; a < i; ++a) {
			for (size_t b = 0; b < i; ++b) {
				if (b == a)
					continue;
				if (sol[a] == sol[b])
					return;
			}
		}
		for (size_t c = 0; c < n; ++c) {
			if (r[c] == 'i' || r[c] == 'I') {
				if (sol[c + 1] < sol[c])
					return;
			}
			else {
				if (sol[c + 1] > sol[c]) {
					return;
				}
			}
		}
		for (size_t k = 0; k < i; ++k) {
			printf("%d ", sol[k]);
		}
		printf("\n");
		return;
	}


	for (size_t j = 0; j <= n; ++j) {
		sol[i] = j + 1;
		RegoleRec(r, n, i + 1, sol);
	}
}
void Regole(const char* r) {
	size_t n = strlen(r);
	if (n == 0) {
		int el = 1;
		printf("%d", el);
		return;
	}
	int* sol = calloc(n+1, sizeof(int));
	RegoleRec(r, n, 0, sol);
	free(sol);
	return;

}