#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
int ContaOccorrenze(const char* filename, const char* str) {
	if (str == NULL)
		return 0;
	FILE* f = fopen(filename, "r");
	if (f == NULL)
		return 0;
	size_t conta = 0;
	size_t l = strlen(str);
	while (1) {
		bool h = true;
		int c = fgetc(f);
		if (c == EOF)
			break;
		if (c == str[0]) {
			for (size_t i = 1; i < l; ++i) {
				c = fgetc(f);
				if (c != str[i])
					h = false;
			}
			if (h == true)
				++conta;
		}
	}
	fclose(f);
	return conta;

}