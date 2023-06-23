#include <stdlib.h>
#include <stdint.h>
void CountingSort(int* v, size_t v_size) {
	int max = INT32_MIN;
	int min = INT32_MAX;
	for (size_t i = 0; i < v_size; ++i) {
		if (v[i] > max)
			max = v[i];
		if (v[i] < min)
			min = v[i];
	}
	int* tmp = calloc((max - min + 1), sizeof(int));

	for (size_t i = 0; i < v_size; ++i) {
		tmp[v[i] - min]++;
	}

	size_t k = 0;
	for (int i = 0; i < max-min+1; ++i) {
		for (int j = 0; j < tmp[i]; ++j) {
			v[k] = i + min;
			++k;
		}
	}
	free(tmp);
}