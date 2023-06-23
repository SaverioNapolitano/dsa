#ifndef GIOIELLI_H
#define GIOIELLI_H
typedef struct {
    int codice;
    float peso;
    float prezzo;
} Gioiello;
extern Gioiello* CompraGioielli(const char* filename, float budget, size_t* ret_size);
#endif // !GIOIELLI_H

