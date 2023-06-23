#include "colora.h"
#include <stdio.h>
#include <math.h>

/// <summary>
///
/// </summary>
/// <param name="m"></param>
/// <param name="c"></param>
/// <param name="c_size"></param>
/// <param name="nsol"></param>
/// <param name="sol"></param>
/// <param name="i"></param>
static void MappaColoriRec(const struct Matrix* m, const char* c, size_t c_size, int *nsol, char*sol, size_t i) {

    if (i == m->size) {
        // rappresenta l'indice nella matrice m
        size_t index = 0;
        for (size_t rows = 0; rows < m->size; ++rows) {
            ++index;
            for (size_t cols = rows+1; cols < m->size; ++cols) {
                if (rows == cols)
                    continue;
                if (m->data[index*cols + rows]) {
                    if (sol[rows] == sol[cols]) {
                        return;
                    }
                }
            }
        }
        (*nsol)++;
        for (size_t a = 0; a < m->size; ++a) {
            printf("%zu -> %c; ", a, sol[a]);
        }
        printf("\n");
        return;
    }

    for (size_t j = 0; j < c_size; ++j) {
        sol[i] = c[j];
        MappaColoriRec(m, c, c_size, nsol, sol, i + 1);
    }

}
int MappaColori(const struct Matrix* m, const char* c, size_t c_size) {
    int nsol = 0;
    char* sol = malloc(m->size * sizeof(char));
    MappaColoriRec(m, c, c_size, &nsol, sol, 0);

    free(sol);
    return nsol;
}
