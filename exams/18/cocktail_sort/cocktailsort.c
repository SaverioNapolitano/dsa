#include <stdlib.h>
#include <stdbool.h>
void CocktailSort(int* v, size_t v_size) {
	if (v == NULL || v_size == 0) {
		return;
	}
	size_t start = 0, end = v_size - 1;
	bool scambio = true;
	bool sinistra = true;
	while (1) {
		scambio = false;
		if (sinistra) {
			for (size_t i = start; i < end; ++i) {

				if (v[i] > v[i + 1]) {
					scambio = true;
					int app = v[i];
					v[i] = v[i + 1];
					v[i + 1] = app;
				}
			}
		}
		else {
			for (size_t i = end; i > start; --i) {
				if (v[i] < v[i-1]) {
					scambio = true;
					int app = v[i];
					v[i] = v[i - 1];
					v[i - 1] = app;
				}
			}
		}
		if (!scambio)
			break;
		if (sinistra) {
			end--;
			sinistra = false;
		}
		else {
			start++;
			sinistra = true;
		}
		if (end <= start)
			break;
	}
}