#include <stdio.h>
void Permutazioni(int n, int i, int vcurr[], int* nsol) {
    int j, tmp;
    if (i == n) {
        printf("%d) ", *nsol);
        (*nsol)++;
        for (int j = 0; j < n; j++) {
            printf("%d ", vcurr[j]);
        } printf("\n");
        return;
    }
    for (int j = i; j < n; j++) {
        tmp = vcurr[i]; vcurr[i] = vcurr[j]; vcurr[j] = tmp;
        Permutazioni(n, i + 1, vcurr, nsol);
        tmp = vcurr[i]; vcurr[i] = vcurr[j]; vcurr[j] = tmp;
    }
}