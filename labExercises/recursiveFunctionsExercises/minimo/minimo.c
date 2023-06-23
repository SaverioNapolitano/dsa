
int Minimo(const int* v, int v_size) {
	v_size--;
	if (v_size == 0) {
		return v[0];
	}
	int min = Minimo(v, v_size);

	if (v[v_size] < min) {
		return v[v_size];
	} else {
		return min;
	}
}