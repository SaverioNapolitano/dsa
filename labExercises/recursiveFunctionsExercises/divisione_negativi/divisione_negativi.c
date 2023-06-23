#include <limits.h>

static int DivisioneNegativiRec(int a, int b, int div) {
	if (a < b)
		return div;
	return DivisioneNegativiRec(a - b, b, ++div);
}
int DivisioneNegativi(int a, int b) {
	if (b == 0)
		return INT_MAX;
	if (a == 0)
		return 0;
	int div = 0;
	if (a > 0 && b > 0)
		return DivisioneNegativiRec(a, b, div);
	if (a < 0 && b < 0)
		return DivisioneNegativiRec(-a, -b, div);
	if (a < 0)
		return -DivisioneNegativiRec(-a, b, div);

	return -DivisioneNegativiRec(a, -b, div);
}