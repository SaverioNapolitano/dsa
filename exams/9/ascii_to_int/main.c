
extern int AToI(const char* str);

int main(void) {
	int a = AToI("3");
	a = AToI("42");
	a = AToI("412");
	a = AToI("123456789");

	return 0;
}