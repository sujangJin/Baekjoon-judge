#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
int n;
long long d[100000][2], ans = -1e3;
int main()
{
	scanf("%d",&n);
	vector<long long> a(n);
	for (int i = 0; i < n; i++) {
		scanf("%lld",&a[i]);
	}
	
	d[0][0] = a[0];
	d[0][1] = -1e3;
	for (int i = 1; i < n; i++) {
		d[i][0] = max(d[i - 1][0] + a[i], a[i]);
		d[i][1] = max(d[i - 1][1] + a[i], d[i - 1][0]);
	}

	for (int i = 0; i < n; i++) {
		ans = max({ ans,d[i][0],d[i][1] });
	}

	printf("%lld",ans);
	return 0;
}