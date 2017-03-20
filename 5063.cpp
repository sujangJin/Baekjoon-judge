#include <cstdio>
int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		int r, e, c;
		scanf("%d %d %d", &r, &e, &c);
		if (r > e - c) puts("do not advertise");
		else if (r < e - c) puts("advertise");
		else puts("does not matter");
	}
	return 0;
}