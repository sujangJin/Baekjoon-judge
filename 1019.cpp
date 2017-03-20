#include<cstdio>
#define ll long long
ll ans[10];
using namespace std;
void calc(ll n, ll ten) {
	while (n > 0) {
		ans[n % 10] += ten;
		n = n / 10;
	}
}
int main()
{
	ll start = 1;
	ll end;
	ll ten = 1;
	scanf("%lld",&end);
	while (start <= end) {
		while (start % 10 != 0 && start <= end) {
			calc(start, ten);
			start += 1;
		}
		if (start > end) break;
		while (end % 10 != 9 && start <= end) {
			calc(end, ten);
			end -= 1;
		}
		ll cnt = (end / 10 - start / 10 + 1);
		for (int i = 0; i <= 9; i++) {
			ans[i] += cnt*ten;
		}
		start /= 10;
		end /= 10;
		ten *= 10LL;
	}
	for (int i = 0; i <= 9; i++) {
		printf("%lld ",ans[i]);
	}
	return 0;
}