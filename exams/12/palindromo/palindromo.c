#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
static bool IsPalindromoRec(const char* str, size_t end, size_t start) {
	if (end <= start)
		return true;
	if (str[start] != str[end])
		return false;
	return IsPalindromoRec(str, end - 1, start + 1);
}
bool IsPalindromo(const char* str) {
	if (str == NULL)
		return false;
	size_t end = strlen(str);
	if (end == 0)
		return true;
	return IsPalindromoRec(str, end-1, 0);
}