#include <stdlib.h>

extern char* ReverseString(const char* str);

int main(void) {
	char str[] = "stringa da invertire";
	size_t l = strlen(str);
	char* r = malloc(l * sizeof(char));
	r = ReverseString(str);

	return 0;
}