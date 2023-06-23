#include <stdlib.h>
static void AssegnaBiscottiRec(const int* bam, size_t bam_size, const int* bis, size_t bis_size, int* ret, size_t i, int *vsol) {
	
	
	if (i == bis_size) {
		int ret_curr = 0;
		for (size_t k = 0; k < bam_size; ++k) {
			if (vsol[k] >= bam[k])
				ret_curr++;
		}
		if (ret_curr > *ret)
			*ret = ret_curr;
		return;
	}

	for (size_t j=0; j < bis_size; ++j) {
		vsol[j] += bis[i];
		AssegnaBiscottiRec(bam, bam_size, bis, bis_size, ret, i + 1, vsol);
		vsol[j] -= bis[i];
	}
}
int AssegnaBiscotti(const int* bam, size_t bam_size, const int* bis, size_t bis_size) {
	if (bam == NULL || bis == NULL || bam_size == 0 || bis_size == 0)
		return 0;
	int ret = 0;
	int* vsol = calloc(bis_size, sizeof(int));
	AssegnaBiscottiRec(bam, bam_size, bis, bis_size, &ret, 0, vsol);

	free(vsol);
	return ret;
}