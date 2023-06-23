#ifndef SCIATORI_H
#define SCIATORI_H
#include <stdint.h>
typedef struct {
    double a;
    double l;
} Sciatore;
extern Sciatore* Accoppia(double* altezze, double* lunghezze, size_t v_size);
#endif // !SCIATORI_H

