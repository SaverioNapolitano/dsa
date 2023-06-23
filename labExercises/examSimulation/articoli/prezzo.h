#ifndef PREZZO_H
#define PREZZO_H
#include <stdlib.h>
struct Articolo {
    char nome[11];
    int prezzo;
};
extern void TrovaArticoli(const struct Articolo* a, size_t a_size, int sum);
#endif // !PREZZO_H

