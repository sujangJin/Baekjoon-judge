#include<cstdio>
using namespace std;
int main()
{
	int n;
	scanf("%d", &n);
	while (n--) {
		int power = 0;
		int h, m, at, am, dh, dm, dat, dam;
		scanf("%d %d %d %d%d %d %d %d", &h, &m, &at, &am, &dh, &dm, &dat, &dam);
		h += dh; m += dm; at += dat; am += dam;
		if (h < 1) h = 1;
		if (m < 1) m = 1;
		if (at < 0) at = 0;
		printf("%d\n", h + 5 * m + 2 * at + 2 * am);
	}
	return 0;
}