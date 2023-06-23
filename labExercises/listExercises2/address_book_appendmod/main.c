#include "list.h"

extern Item* AppendMod(Item* i1, Item* i2);

int main(void) {
	ElemType e2[] = { {"Michele", "Firenze", 12, "Modena", "MO", "41126"},
				{"Federico", "Peschiera", 54, "Modena", "MO", "41126"},
		{"Massimiliano", "Roma", 23, "Firenze", "FI", "50100"},
		{"Massimiliano", "Newton", 23, "Modena", "MO", "41126"},
		{"Stefano", "Ciro Menotti", 10, "Milano", "MI", "20019"} };
	size_t e2_size = sizeof(e2) / sizeof(ElemType);
	Item* i2 = ListCreateEmpty();
	for (size_t i = 0; i < e2_size; ++i) {
		i2 = ListInsertBack(i2, e2 + i);
	}

	/*ElemType e2[] = { NULL };
	size_t e2_size = sizeof(e2) / sizeof(ElemType);*/
	Item* i1 = ListCreateEmpty();
	/*for (size_t i = 0; i < e2_size; ++i) {
		i2 = ListInsertBack(i2, e2 + i);
	}*/

	Item* r = AppendMod(i1, i2);

	return 0;
}