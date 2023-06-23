#include <stdlib.h>
#include <string.h>
static int FindMaxIndex(int* v, int v_size) {
	int max_index = 0;
	for (int i = 0; i < v_size - 1; ++i) {
		if (v[max_index] < v[i + 1])
			max_index = i + 1;
	}
	return max_index;
}
static void Flip(int* v, int v_size) {
	int* v_copy = malloc((v_size+1) * sizeof(int));
	memcpy(v_copy, v, (v_size+1)*sizeof(int));
	for (int i = 0, j = v_size; i <= v_size && j >= 0; ++i, --j) {
		v[i] = v_copy[j];
	}
	free(v_copy);
}
void PancakeSort(int* v, size_t v_size) {
	int curr_size = (int)v_size;
	while (curr_size > 1) {
		int m = FindMaxIndex(v, curr_size);
		Flip(v, m);
		Flip(v, curr_size - 1);
		curr_size--;
	}
}