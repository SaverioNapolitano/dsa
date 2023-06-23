

static int MCDRec(int m, int n) {
	if (n == 0)
		return m;
	return MCDRec(n, m % n);
}
int MCD(int m, int n) {
	if (m < n) {
		int c = m;
		m = n;
		n = c;
	}
	return MCDRec(m, n);
}