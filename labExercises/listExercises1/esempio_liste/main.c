#include "list.h"
#include <stdlib.h>

int main(void) {
	ElemType e[] = { 0, 1, 2, 3, 4 };
	size_t e_size = sizeof(e) / sizeof(ElemType);
	Item* l = ListCreateEmpty(); // Item *l = NULL; non c'è una meglio dell'altra

	l = ListInsertHead(e + 0, l);//&e[0]
	l = ListInsertHead(e + 1, l);
	l = ListInsertHead(e + 2, l);
	l = ListInsertHead(e + 3, l);
	l = ListInsertHead(e + 4, l);

	for (size_t i = 0; i < e_size; ++i) {
		l = ListInsertHead(e + i, l);
	}
	{
		Item* tmp = l; //non è una copia della lista, ma dell'indirizzo del primo elemento 
		while (!ListIsEmpty(tmp)) {
			//ElemWriteStdout(ListGetHeadValue(l));
			tmp = ListGetTail(tmp);
		}
	}
	{
		Item* tmp = l; 
		while (tmp) {
			//printf("%d", tmp->value);
			tmp = tmp->next;
		}
	}
	{
		for (Item* tmp = l; !ListIsEmpty(tmp); tmp = ListGetTail(tmp) {
			//ElemWriteStdout(ListGetHeadValue(l));
		}
	}
	for (Item* tmp = l; tmp; tmp = tmp->next) {
		//ElemWriteStdout(ListGetHeadValue(l));
	}

	ListDelete(l);
	return EXIT_SUCCESS;
}