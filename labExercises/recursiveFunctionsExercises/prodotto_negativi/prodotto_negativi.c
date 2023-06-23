
static int ProdottoNegativiRec(int x, int y, int prod) {
	if (y == 0)
		return prod;
	return ProdottoNegativiRec(x, --y, prod += x);
}
int ProdottoNegativi(int a, int b) {
	if (a == 0 || b == 0)
		return 0;
	int p = 0;
	if (a > 0 && b > 0)
		return ProdottoNegativiRec(a, b, p);
	if (a < 0 && b < 0)
		return ProdottoNegativiRec(-a, -b, p);

	if (a < 0)
		return -ProdottoNegativiRec(-a, b, p);

	return -ProdottoNegativiRec(a, -b, p);

}