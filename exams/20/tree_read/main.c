#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>
#include "tree.h"

extern Node* TreeRead(const char* filename);

int main(void) {
	Node* r = TreeCreateEmpty();
	r = TreeRead("albero50.txt");

	TreeDelete(r);

	_CrtDumpMemoryLeaks();

	return 0;
}