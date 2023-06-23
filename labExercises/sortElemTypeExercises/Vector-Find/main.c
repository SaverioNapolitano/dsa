#include "vettore.h"
#include <stdlib.h>
int main(void) {
	Vector *v = malloc(sizeof(Vector));
	v->size = 25;
	v->capacity = 50;
	v->data = malloc(v->capacity * sizeof(ElemType));

	v->data[0] = -12; v->data[1] = -4; v->data[2] = -2; v->data[3] = -1;
	v->data[4] = 0; v->data[5] = 0; v->data[6] = 4; v->data[7] = 5;
	v->data[8] = 6; v->data[9] = 6; v->data[10] = 7; v->data[11] = 8;
	v->data[12] = 34; v->data[13] = 34; v->data[14] = 54; v->data[15] = 56;
	v->data[16] = 234; v->data[17] = 346; v->data[18] = 367; v->data[19] = 435;
	v->data[20] = 1233; v->data[21] = 3453; v->data[22] = 3456; v->data[23] = 4567;
	v->data[24] = 9999;
	
	int e = -12;
	int t = VectorFind(v, &e);

	return 0;
}