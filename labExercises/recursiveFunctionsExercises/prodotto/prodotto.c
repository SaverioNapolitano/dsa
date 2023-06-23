static int ProdottoRec(int x, int y, int prod) {
	if (y == 0) 
		return prod;
	return ProdottoRec(x, --y, prod+=x);
}
int Prodotto(int a, int b) {
	if (a < 0 || b < 0)
		return -1;
	if (a == 0 || b == 0)
		return 0;
	int p = 0;
	return ProdottoRec(a, b, p);
}