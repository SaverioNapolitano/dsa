#include <stdlib.h>
#include <math.h>
#include <string.h>
static int AToIRec(const char* str, int len, int ret, int i) {
	if (len == 0)
		return ret;
	ret += ((int)str[len-1]-48) * (int)pow(10, i);
	--len;
	++i;
	return AToIRec(str, len, ret, i);
}
int AToI(const char* str) {
	if (str == NULL)
		return 0;
	size_t len = strlen(str);
	return AToIRec(str, (int)len, 0, 0);
}