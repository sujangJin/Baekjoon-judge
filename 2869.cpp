#include<cstdio>
using namespace std;
long long a, b, v, days, now;
int main()
{
	scanf("%lld %lld %lld", &a, &b, &v);
	while (now < v) {
		days++;
		now += a;
		if (now >= v) break;
		now -= b;
	}
	printf("%lld", days);
	return 0;
}