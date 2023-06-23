#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void PasswordRec(const char* str, int n, int i, int* vcurr, size_t len, int* nsol) {
	if (i == n) {
		(*nsol)++;
		for (int k = 0; k < n; k++) {
			printf("%c", str[vcurr[k]]);
		}
		printf("\n");
		return;
	}

	for (int j = 0; j < (int)len; j++) {
		vcurr[i] = j;
		PasswordRec(str, n, i + 1, vcurr, len, nsol);
	}

}

int Password(const char* str, int n) {
	if (str == NULL) {
		return 0;
	}

	size_t len = strlen(str);
	int nsol = 0;
	int* vcurr = calloc(n, sizeof(int));

	PasswordRec(str, n, 0, vcurr, len, &nsol);

	free(vcurr);
	return nsol;
}
