#include "tree.h"

static void LevelOrderRec(const Node* t, size_t i, size_t *target, size_t *printed) {
	
	if (TreeIsEmpty(t))
		return;

	if (i == *target) {
		ElemWriteStdout(&t->value);
		printf(" ");
		(*printed)++;
		return;
	}
	LevelOrderRec(TreeLeft(t), i + 1, target, printed);
	LevelOrderRec(TreeRight(t), i + 1, target, printed);
}
void LevelOrder(const Node* t) {
	size_t target = 0;
	size_t printed = 0;
	while (1) {
		LevelOrderRec(t, 0, &target, &printed);
		if (printed == 0)
			break;
		target++;
		printed = 0;
	}
	return;
}