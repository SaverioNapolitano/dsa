#include <stdio.h>
#include <stdlib.h>
#include "gioielli.h"
int main(void) {
	char f[]="gioielli_1.txt";
	size_t ret;
	Gioiello* r = CompraGioielli(f, 130, &ret);

	return 0;
}