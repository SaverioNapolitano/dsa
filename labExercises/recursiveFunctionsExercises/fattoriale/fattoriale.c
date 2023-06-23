static unsigned long long FattorialeRec(int n, unsigned long long r) {
	if (n==0 || n == 1)
		return r;
	return FattorialeRec(n - 1, r*n);
}
unsigned long long Fattoriale(int n) {
	if (n < 0)
		return 0;
	unsigned long long f = 1;
	return FattorialeRec(n, f);
}
