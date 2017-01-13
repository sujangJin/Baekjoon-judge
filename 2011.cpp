#include <cstdio>
char str[5001];
int d[5001];
const int MOD = 1000000;
int main() {
	int idx = 1;
	for (; ~scanf("%1c", str + idx); idx++);
	d[0] = 1;
	if (str[1] != '0') d[1] = 1;
	else { puts("0"); return 0; }
	for (int i = 2; i<idx; i++) {
		if (str[i] == '0') { d[i] = d[i - 2]; continue; }
		if (str[i - 1] == '0') { d[i] = d[i - 1]; continue; }
		int tmp = (str[i - 1] - '0') * 10 + str[i] - '0';

		if (tmp <= 26) d[i] = (d[i - 1] + d[i - 2]) % MOD;
		else if (tmp > 0) d[i] = d[i - 1] % MOD;
	}
	printf("%d", d[idx - 1]);
	return 0;
}