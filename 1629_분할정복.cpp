#include<cstdio>
#define ll long long
ll mul(ll a, ll b, ll c) {
	if (b == 0) {
		return 1;
	}
	else if (b == 1) {
		return a%c;
	}
	else if (b & 1) {
		ll tmp = mul(a, b / 2, c);
		return (tmp*tmp) % c;
	}
	else {
		return (a*mul(a, b - 1, c)) % c;
	}
}
int main() {
	ll a, b, c;
	scanf("%lld %lld %lld", &a, &b, &c);
	printf("%lld", mul(a, b, c));
	return 0;
}