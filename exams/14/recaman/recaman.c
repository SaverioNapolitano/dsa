#include <stdlib.h>

static void RecamanRec(int n, int *ret, int i) {
	if (i == n)
		return;
	if (*ret % i == 0) {
		*ret /= i;
	}
	else {
		*ret *= i;
	}
	RecamanRec(n, ret, i + 1);
}
int Recaman(int n) {
	if (n < 1)
		return -1;
	int ret = 1;
	RecamanRec(n, &ret, 1);
	return ret;
}