#include "tree.h"

static void TreeFindHRec(const Node* t, int i, int* h) {
	if (TreeIsLeaf(t)) {
		if (i > *h) {
			*h = i;
		}
		return;
	}
	TreeFindHRec(TreeLeft(t), i + 1, h);
	TreeFindHRec(TreeRight(t), i + 1, h);
}
static void DiameterRec(const Node* t, int* d) {

	if(!TreeIsEmpty(TreeLeft(t)))
		TreeFindHRec(TreeLeft(t), 1, d);
	int ret = *d;
	if(!TreeIsEmpty(TreeRight(t)))
		TreeFindHRec(TreeRight(t), 1, d);
	ret += *d;
	*d = ret + 1;
	return;
}
int Diameter(const Node* t) {
	if (TreeIsEmpty(t))
		return 0;
	int d_root = 0;
	int h_left = 0;
	TreeFindHRec(TreeLeft(t), 1, &h_left);
	int h_right = 0;
	TreeFindHRec(TreeRight(t), 1, &h_right);
	int d_left = 0;
	int d_right = 0;
	DiameterRec(TreeLeft(t), &d_left);
	DiameterRec(TreeRight(t), &d_right);
	d_root = h_left + h_right + 1;
	if (d_right >= d_root && d_right >= d_left)
		return d_right;
	if (d_left >= d_root && d_left >= d_right)
		return d_left;

	return d_root;
}