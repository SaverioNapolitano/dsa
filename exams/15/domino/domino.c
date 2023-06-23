#include "domino.h"
#include <string.h>
#include <stdlib.h>
static void DominoRec(const Tessera* t, size_t t_size, size_t* ret_size, Placing *pcurr, Placing*psol,  size_t i, int curr_size, size_t j) {

	if (curr_size > 0) {
		for (int a = 0; a <= curr_size; ++a) {
			uint32_t index = pcurr[a].indice;
			for (int b = 0; b <= curr_size; ++b) {
				if (b == a) {
					continue;
				}
				if (pcurr[b].indice == index) {
					return;
				}
			}
		}
		if (!pcurr[curr_size - 1].flipped) {
			if (!pcurr[curr_size].flipped) {
				if (t[pcurr[curr_size-1].indice].val2 != t[pcurr[curr_size].indice].val1) {
					return;
				}
			}
			else {
				if (t[pcurr[curr_size - 1].indice].val2 != t[pcurr[curr_size].indice].val2) {
					return;
				}
			}
		}
		else {
			if (!pcurr[curr_size].flipped) {
				if (t[pcurr[curr_size - 1].indice].val1 != t[pcurr[curr_size].indice].val1) {
					return;
				}
			}
			else {
				if (t[pcurr[curr_size - 1].indice].val1 != t[pcurr[curr_size].indice].val2) {
					return;
				}
			}
		}
		if ((size_t)curr_size > *ret_size) {
			*ret_size = (size_t)curr_size;
			for (int c = 0; c <= curr_size; ++c) {
				psol[c] = pcurr[c];
			}
		}
	}


	for (; j < t_size; ++j) {
		pcurr[i].indice = j;
		for (size_t l = 0; l < 2; ++l) {
			pcurr[i].flipped = l;
			DominoRec(t, t_size, ret_size, pcurr, psol, i + 1, curr_size + 1, j + 1);
		}
		pcurr[i].indice = UINT32_MAX;
	}
}
Placing* Domino(const Tessera* t, size_t t_size, size_t* ret_size) {
	*ret_size = 0;
	if (t == NULL || t_size == 0) {
		return NULL;
	}
	Placing* pcurr = malloc(t_size * sizeof(Placing));
	for (size_t k = 0; k < t_size; ++k) {
		pcurr[k].indice = UINT32_MAX;
	}
	Placing* psol = malloc(t_size * sizeof(Placing));

	DominoRec(t, t_size, ret_size, pcurr, psol, 0, -1, false);
	(*ret_size)++;
	free(pcurr);
	return psol;
}