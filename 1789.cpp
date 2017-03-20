#include<cstdio>
#define ll long long
using namespace std;
ll s;
int main()
{
	scanf("%lld", &s);
	ll i=1;
	for (; i*(i + 1) <= 2 * s; i++);
	printf("%lld", i-1);
	return 0;
}