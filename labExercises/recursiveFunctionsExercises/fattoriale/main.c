#include <stdlib.h>
extern unsigned long long Fattoriale(int n);
int main(void) {
	unsigned long long f;
	f = Fattoriale(0);
	f = Fattoriale(1);
	f = Fattoriale(2);
	f = Fattoriale(3);
	f = Fattoriale(4);
	f = Fattoriale(20);

	return EXIT_SUCCESS;
}