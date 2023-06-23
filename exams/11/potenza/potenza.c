
static int PotenzaRec(int a, int b, int ret) {
	if (b == 0)
		return ret;
	return PotenzaRec(a, b - 1, ret*a);
}
int Potenza(int a, int b) {
	if (b == 0)
		return 1;
	return PotenzaRec(a, b, 1);
}