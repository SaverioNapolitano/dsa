#include "tree.h"
#include <float.h>


static void TreeFindNodes(const Node* t, size_t *i) {
	if (TreeIsEmpty(t))
		return;
	(*i)++;
	TreeFindNodes(TreeLeft(t), i);
	TreeFindNodes(TreeRight(t), i);
}
static void MedianoRec(const Node* t, size_t* i, size_t *target, size_t n, double* ret, size_t *count) {
	if (TreeIsEmpty(t))
		return;
	MedianoRec(TreeLeft(t), i, target, n, ret, count);
	if (*i == *target) {
		if (n % 2 != 0 && *ret==0) {
			*ret += (double)*TreeGetRootValue(t);
			return;
		}
		if ((*ret == 0 || *count<2)&&n%2==0) {
			*ret += (double)*TreeGetRootValue(t);
			(*target)++;
			(*count)++;
		}
	}
	(*i)++;
	MedianoRec(TreeRight(t), i, target, n, ret, count);
}
double Mediano(const Node* t) {
	if (TreeIsEmpty(t))
		return DBL_MAX;
	size_t n = 0;
	TreeFindNodes(t, &n);
	size_t target = n / 2;
	double ret = 0;
	size_t i = 0;
	size_t count = 0;
	if (n % 2 == 0)
		++i;
	MedianoRec(t, &i, &target, n, &ret, &count);
	if (n % 2 == 0)
		ret /= 2;
	return ret;
}