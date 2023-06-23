#define _CRT_SECURE_NO_WARNINGS
#include "list.h"
#include <stdlib.h>
extern Item* ListLoad(const char* filename);
int main(void) {
	Item* ret = NULL;
	char s[] = "data_00.txt";
	ret = ListLoad(s);

	return EXIT_SUCCESS;
}