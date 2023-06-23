#include "sciatori.h"
int main(void) {
	double altezze[] = { 81.50, 34.20, 100.00, 96.80 };
	double lunghezze[] = { 100.20, 200.10, 30.10, 150.12 };
	Sciatore* ret = malloc(4 * sizeof(Sciatore));
	ret = Accoppia(altezze, lunghezze, 4);

	return 0;
}