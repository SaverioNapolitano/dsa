#include "list.h"

extern Item* Differenza(const Item* i1, const Item* i2);

int main(void) {
    ElemType e1[] = { '1', '2', '3' };
    size_t e1_size = sizeof(e1) / sizeof(ElemType);

    Item* list_a = ListCreateEmpty();
    for (size_t i = 0; i < e1_size; ++i) {
        list_a = ListInsertBack(list_a, e1 + i);
    }

    ElemType e2[] = { '3', '2', '4'};
    size_t e2_size = sizeof(e2) / sizeof(ElemType);

    Item* list_b = ListCreateEmpty();
    for (size_t i = 0; i < e2_size; ++i) {
        list_b = ListInsertBack(list_b, e2 + i);
    }

    Item* d = ListCreateEmpty();
    d = Differenza(list_a, NULL);

    ListDelete(list_a);
    ListDelete(list_b);

    return 0;

}