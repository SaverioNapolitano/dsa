#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
static void ParoleT9Rec(const char* str, size_t len, char** s, int* nsol, char *scurr, size_t i) {
	
	if (i == len) {
		size_t index = 0;
		bool valid = false;
		while (index < len) {
			valid = false;
			for (size_t k = 0; k < strlen(s[index]); ++k) {
				if (scurr[index] == s[index][k])
					valid = true;
			}
			if (!valid)
				return;
			++index;
		}
		(*nsol)++;
		for (size_t a = 0; a < len; ++a) {
			printf("%c", scurr[a]);
		}
		printf("\n");
		return;
	}

	for (size_t j = 0; j < strlen(s[i]); ++j) {
		scurr[i] = s[i][j];
		ParoleT9Rec(str, len, s, nsol, scurr, i + 1);
	}
}
int ParoleT9(const char* str) {
	if (str == NULL)
		return 0;
	size_t len = strlen(str);
	if (len == 0)
		return 0;
	char** s = calloc(len, sizeof(char*));
	for (size_t i = 0; i < len; ++i) {
		if (str[i] == '2')
			s[i] = "ABC";
		if (str[i] == '3')
			s[i] = "DEF";
		if (str[i] == '4')
			s[i] = "GHI";
		if (str[i] == '5')
			s[i] = "JKL";
		if (str[i] == '6')
			s[i] = "MNO";
		if (str[i] == '7')
			s[i] = "PQRS";
		if (str[i] == '8')
			s[i] = "TUV";
		if (str[i] == '9')
			s[i] = "WXYZ";
	}
	char* scurr = malloc(len * sizeof(char));
	int nsol = 0;
	ParoleT9Rec(str, len, s, &nsol, scurr, 0);

	free(s);
	free(scurr);
	return nsol;
}