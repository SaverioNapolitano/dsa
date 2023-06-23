#include <stdlib.h>

extern int AssegnaBiscotti(const int* bam, size_t bam_size, const int* bis, size_t bis_size);

int main(void) {
	int bam[] = { 10, 10, 10 };
	int	bis[] = { 10, 12, 14 };

	int n = AssegnaBiscotti(bam, 3, bis, 3);

	return 0;
}