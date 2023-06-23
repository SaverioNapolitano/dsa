#include <stdlib.h>
#include <stdint.h>

#include "tree.h"

static size_t TrovaMin(const ElemType* v, size_t start, size_t end)
{
	size_t min = start;
	for (size_t i = start + 1; i <= end; i++)
	{
		if (v[i] < v[min])
		{
			min = i;
		}
	}

	return min;
}

static Node* CreateMinBinTreeRec(const ElemType* v, size_t start, size_t end)
{
	if (start <= end && end != SIZE_MAX) {
		size_t min = TrovaMin(v, start, end);

		return TreeCreateRoot(v + min, CreateMinBinTreeRec(v, start, min - 1), CreateMinBinTreeRec(v, min + 1, end));
	}

	return TreeCreateEmpty();

}

Node* CreateMinBinTree(const ElemType* v, size_t v_size)
{
	if (v == NULL || v_size == 0) {
		return NULL;
	}

	return CreateMinBinTreeRec(v, 0, v_size - 1);
}