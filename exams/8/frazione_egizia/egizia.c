#include <stdio.h>
#include <math.h>
static void FrazioneEgiziaRec(int n, int d, int n1, int d1, int nr, int dr, int ds) {
	dr = d * d1;
	nr = n * d1 - d * n1;
	ds = (int)ceil((double)dr / nr);
	printf(" + 1/%d", ds);
	if (dr % nr == 0)
		return;
	n = n*ds - d;
	d = d*ds;
	FrazioneEgiziaRec(n, d, n1, d1, nr, dr, ds);
}
void FrazioneEgizia(int n, int d) {
	if (n <= 0 || d <= 0 || n >= d) {
		printf("Impossibile convertire la frazione data in frazione egizia.");
		return;
	}
	int r = (int)ceil((double)d / n);
	printf("1/%d", r);
	FrazioneEgiziaRec(n, d, 1, r, 0, 0, 0);
	return;
}