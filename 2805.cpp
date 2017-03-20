#include<cstdio>
int n;
long long m, l, r, ans;
long long a[1000000];
bool chk(long long x) {
	long long cnt = 0;
	for (int i = 0; i < n; i++)
		if (a[i] - x > 0) {
			cnt += a[i] - x;
		}
	return cnt >= m;
}
int main()
{
	scanf("%d %lld",&n,&m);
	for (int i = 0; i < n; i++) {
		scanf("%lld", a + i);
		if (r < a[i]) r = a[i];
	}
	while (l <= r) {
		long long mid = (l + r) / 2;
		if (chk(mid)) {
			if (ans < mid) ans = mid;
			l = mid + 1;
		}
		else {
			r = mid - 1;
		}
	}
	printf("%lld",ans);
	return 0;
}