#include <cstdio>
const int MAX = 1000000;
int n, m;
bool chk[MAX+1];
int main() {
	chk[0] = chk[1] = true;
	for (int i = 2; i*i <= MAX; i++) {
		if (!chk[i]) {
			for (int j = i + i; j <= MAX; j += i) chk[j] = true;
		}
	}
	scanf("%d%d", &n, &m);
	for (int i = n; i <= m; i++) {
		if (!chk[i]) printf("%d\n",i);
	}
	return 0;
}