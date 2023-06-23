#include "tree.h"
#include <math.h>
static void TreeIsMirrorRec(const Node*t_left, bool *mirror, const Node*t_right) {
	if (!mirror)
		return;
	if (TreeIsEmpty(t_left) && TreeIsEmpty(t_right))
		return;
	if ((TreeIsEmpty(t_left) && !TreeIsEmpty(t_right)) || (!TreeIsEmpty(t_left) && TreeIsEmpty(t_right))) {
		*mirror = false;
		return;
	}
	if (ElemCompare(TreeGetRootValue(t_left), TreeGetRootValue(t_right)) != 0) {
		*mirror = false;
		return;
	}
	TreeIsMirrorRec(TreeLeft(t_left), mirror, TreeRight(t_right));
	if (mirror)
		TreeIsMirrorRec(TreeRight(t_left), mirror, TreeLeft(t_right));
	else
		return;
	
}
bool TreeIsMirror(const Node* t) {
	if (TreeIsEmpty(t) || (TreeIsEmpty(TreeLeft(t)) && TreeIsEmpty(TreeRight(t))))
		return true;
	bool mirror = true;
	TreeIsMirrorRec(TreeLeft(t), &mirror, TreeRight(t));
	return mirror;
}