#include "prezzo.h"

int main(void) {
	struct Articolo b = { "Monopoli", 20};
	struct Articolo c = { "Carcassone", 30 };
	struct Articolo d = { "Perudo", 20 };
	struct Articolo* a = malloc(3 * sizeof(struct Articolo));
	a[0] = b;
	a[1] = c;
	a[2] = d;
	TrovaArticoli(a, 3, 50);

	return 0;
}