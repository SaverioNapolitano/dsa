#include <stdio.h>
#include <string.h>
int main(int argc, char** argv) {
	if (argc != 3) {
		fprintf(stderr, "Il numero di parametri non e' corretto. Sintassi del programma: \"occorenze <s> < c>\"");
		return 1;
	}
	size_t l = strlen(argv[1]);
	int conta = 0;
	for (size_t i = 0; i < l; ++i) {
		if (argv[1][i] == argv[2][0])
			++conta;
	}
	printf("%d", conta);
	return 0;

}