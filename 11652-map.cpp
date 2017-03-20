#include<cstdio>
#include<map>
#include<vector>
#include<algorithm>
using namespace std;
int n, m;
long long ans;
map<long long, int> d;
int main()
{
	scanf("%d", &n);
	while (n--) {
		long long x;
		scanf("%lld", &x);
		d[x]++;
	}
	for (auto &p : d) {
		if (p.second > m) {
			m = p.second;
			ans = p.first;
		}
		else if (p.second == m && p.first < ans) {
			ans = p.first;
		}
	}
	printf("%lld", ans);
	return 0;
}