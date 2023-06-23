#ifndef TORRECARTONI_H
#define TORRECARTONI_H
#include <stdint.h>
typedef struct {
    unsigned p; // Peso
    unsigned a; // Altezza
    unsigned l; // Limite
} Cartone;
extern void TorreCartoni(const Cartone* c, size_t n);
#endif // !defined TORRECARTONI_H_
