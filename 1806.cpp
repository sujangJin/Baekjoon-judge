#include<cstdio>
#include<algorithm>
using namespace std;
int a[100001];
int main()
{
	int n;
	long long s;
	scanf("%d %lld", &n, &s);
	for (int i = 0; i < n; i++) scanf("%d", a + i);
	// two pointer
	// i : the former pointer
	// j : minimize the length, the latter pointer
	int i, j, len=n+1;
	long long sum;
	for (sum=i=j=0; i < n; i++) {
		sum += a[i];
		if (sum >= s) {
			for (; j <= i; j++) {
				if (sum - a[j] >= s) {
					sum -= a[j];
				}
				else break;
			}
			len = min(len, i - j + 1);
		}
	}
	printf("%d",len==n+1?0:len);
	return 0;
}