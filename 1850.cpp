#include<cstdio>
#include<cmath>
using namespace std;
long long a,b,g;
long long gcd(long long x,long long y) {
	if (y == 0) return x;
	else return gcd(y, x%y);
}
int main()
{
	scanf("%lld %lld",&a,&b);
	g = gcd(a,b);
	while (g > 0) {
		printf("1");
		g--;
	}
	return 0;
}