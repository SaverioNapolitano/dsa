#include <stdlib.h>
#include <stdio.h>
#include <stdio.h>
long long Catalan(long long n) {
	if (n == 0)
		return 1;

	long long ret = 0;
	for (long long i = 0; i <= n - 1; ++i) {
		ret += Catalan(i) * Catalan(n - i - 1);
	}
	return ret;
}
int main(int argc, char** argv) {
	if (argc != 2)
		return 1;
	char* endptr;
	long long n = strtoll(argv[1], &endptr, 10);
	if (endptr[0] != 0 || n < 0)
		return 1;
	long long c = Catalan(n);
	printf("%lli", c);
	return 0;
}