#include "vettore.h"

int main(void) {
	struct vettore *v = malloc(sizeof(struct vettore));
	v->size=5;
	v->data = malloc(v->size * sizeof(int));
	v->data[0] = 1;
	v->data[1] = 2;
	v->data[2] = 3;
	v->data[3] = 4;
	v->data[4] = 5;

	Pop(v);
	//Push(v, 6);

	return 0;
}