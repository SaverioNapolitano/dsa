#include "colora.h"

int main(void) {
	struct Matrix* m = malloc(sizeof(struct Matrix));
	m->size = 3;
	m->data = malloc(sizeof(bool) * m->size);
	m->data[0] = 1; m->data[1] = 1; m->data[2] = 1;
	m->data[3] = 1; m->data[4] = 1; m->data[5] = 0;
	m->data[6] = 1; m->data[7] = 0; m->data[8] = 1;
	char c[] = { 'r','v','b'};
	int ret = MappaColori(m, c, 3);

	return 0;
}