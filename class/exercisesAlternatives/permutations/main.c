
extern void Permutazioni(int n, int i, int vcurr[], int* nsol);

int main(void) {
	int v[] = { 1, 2, 3 };
	int s = 0;
	Permutazioni(3, 0, v, &s);

	return 0;
}