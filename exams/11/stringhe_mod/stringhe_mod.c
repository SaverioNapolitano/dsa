#include <stdlib.h>
#include <stdio.h>

static void BacktrackStrModRec(int n, int k, char*sol, int i) {
	if (i == k) {
		printf("{");
		for (int a = 0; a < k; ++a) {
			printf("%c", sol[a]);
		}
		printf("}, ");
		return;
	}
	for (char j = 'a'; j < 'a' + (char)n; ++j) {
		sol[i] = j;
		BacktrackStrModRec(n, k, sol, i + 1);
	}
}
void BacktrackStrMod(int n, int k) {
	if (n <= 0 || k <= 0 || n > 26)
		return;
	char* sol = malloc(k * sizeof(char));
	BacktrackStrModRec(n, k, sol, 0);
	free(sol);
	return;
}