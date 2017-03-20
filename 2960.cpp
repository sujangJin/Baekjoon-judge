#include<cstdio>
bool a[1001];
int n, k, cnt, val;
int main()
{
	scanf("%d %d",&n,&k);
	for (int i = 2; i <= n; i++) {
		if (a[i]) continue;
		a[i] = true;
		cnt++;
		val = i;
		if (cnt == k) {
			printf("%d", val);
			return 0;
		}
		for (int j = i * i; j <= n; j += i) {
			if (a[j]) continue;
			a[j] = true;
			cnt++;
			val = j;
			if (cnt == k) {
				printf("%d",val);
				return 0;
			}
		}
	}
	return 0;
}