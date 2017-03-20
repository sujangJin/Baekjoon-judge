#include<cstdio>
#include<algorithm>
using namespace std;
const int MAX = 1e6;
long long a[MAX], ans;
int n, cnt = 1, ans_cnt = 1;
int main()
{
	scanf("%d", &n);
	for (int i = 0; i<n; i++) scanf("%lldf", a + i);
	sort(a, a + n);

	ans = a[0];
	for (int i = 1; i<n; i++) {
		if (a[i] == a[i - 1]) cnt++;
		else cnt = 1;

		if (ans_cnt < cnt) {
			ans_cnt = cnt;
			ans = a[i];
		}
	}
	printf("%lld", ans);
	return 0;
}