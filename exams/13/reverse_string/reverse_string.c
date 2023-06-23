#include <stdlib.h>
#include <string.h>
static void ReverseStringRec(const char *str, char** r, size_t i, int len) {
	if (len < 0)
		return;
	r[0][i] = str[len];
	ReverseStringRec(str, r, i + 1, len - 1);
}
char* ReverseString(const char* str) {
	if (str == NULL)
		return NULL;
	size_t len = strlen(str);
	char* r = calloc(len + 1, sizeof(char));
	ReverseStringRec(str, &r, 0, (int)(len-1));
	return r;
}