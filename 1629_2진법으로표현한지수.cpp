#include<cstdio>
#define ll long long
using namespace std;
ll mul(ll a, ll b, ll c) {
	ll ans = 1;
	while (b > 0) {
		if (b % 2 == 0) ans = (ans*a) % c;
		a = (a*a) % c;
		b /= 2;
	}
	return ans;
}
int main() {
	ll a, b, c;
	scanf("%lld %lld %lld", &a, &b, &c);
	printf("%lld", mul(a, b, c));
	return 0;
}