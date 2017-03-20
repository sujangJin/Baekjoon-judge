#include<cstdio>
#include<algorithm>
using namespace std;
long long d[101];
int n;
int main()
{
	scanf("%d",&n);
	d[1] = 1; d[2] = 2; d[3] = 3;
	for (int i = 4; i <= n; i++) {
		long long tmp = i;
		for (int j = i - 3; j >= 1; j--) {
			tmp = max(tmp, (i - j - 1) *d[j]);
		}
		d[i] = tmp;
	}
	printf("%lld",d[n]);
	return 0;
}