


extern int TempoTrasporto(int n, const int* t, int p);

int main(void) {
    int n = 7;
    int t[] = { 4, 4, 4, 5, 3, 1 };
    int p = 100;

    int m = TempoTrasporto(n, t, p);

    return 0;
}