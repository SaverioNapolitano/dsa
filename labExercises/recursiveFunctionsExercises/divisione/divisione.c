static int DivisioneRec(int x, int y, int d) {
	if (x < y)
		return d;
	return DivisioneRec(x - y, y, ++d);
}
int Divisione(int a, int b) {
	if (a < 0 || b <= 0)
		return -1;
	if (a == 0)
		return 0;
	int div = 0;
	return DivisioneRec(a, b, div);
}