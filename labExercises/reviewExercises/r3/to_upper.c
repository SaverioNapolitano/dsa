#include <stdlib.h>

void ToUpper(char* str) {
	if (str != NULL) {
		for (char i = 0; *(str + i) != 0; ++i) {
			if (*(str + i) >= 97 && *(str + i) <= 122) {
				*(str + i) -= 32;
			}
		}
	}
}