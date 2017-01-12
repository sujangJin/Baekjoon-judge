#include<cstdio>
long long a[31];
int n;
int main()
{
	scanf("%d",&n);
	if (n % 2 != 0) { puts("0"); return 0; }
	a[0] = 1;
	for (int i = 2; i <= n; i += 2) {
		a[i] = 3 * a[i - 2];
		for (int j = i - 4; j >= 0; j -= 2) a[i] += 2 * a[j];
	}
	printf("%lld",a[n]);
	return 0;
}