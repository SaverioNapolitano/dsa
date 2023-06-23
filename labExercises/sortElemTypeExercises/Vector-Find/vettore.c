#include "vettore.h"

int VectorFind(const Vector* v, const ElemType* e) {
	int index = -1;
	if (v == NULL || ElemCompare(&v->data[0], e) == 1 || ElemCompare(&v->data[v->size - 1], e) == -1)
		return index;
	int primo = 0;
	int ultimo = v->size - 1;
	size_t i;
	while (primo<=ultimo) {
		i = (primo + ultimo) / 2;
		if (ElemCompare(&v->data[i], e) == 1)
			ultimo = i - 1;
		else 
			if (ElemCompare(&v->data[i], e) == -1)
				primo=i+1;
			else
				if (ElemCompare(&v->data[i], e) == 0) {
					index = i;
					break;
				}
	}
	if (index > 0) {
		for (int j = 0; j < index; ++j) {
			if (ElemCompare(&v->data[j], &v->data[index]) == 0) {
				index = j;
			}
		}
	}
	return index;
}