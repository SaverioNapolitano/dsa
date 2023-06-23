#include <stdlib.h>

void GnomeSort(int* v, size_t v_size) {

	if (v_size <= 1)
		return;
	size_t i = 0;
	while (i < v_size) {
		if (i == 0)
			++i;
		if (v[i] >= v[i - 1])
			++i;
		else {
			int tmp = v[i-1];
			v[i - 1] = v[i];
			v[i] = tmp;
			--i;
		}
	}
}