#include<cstdio>
#include<algorithm>
using namespace std;
int a, b, gcd;
int GCD(int x, int y) {
	if (y == 0) return x;
	else return GCD(y, x%y);
}
int main()
{
	scanf("%d %d",&a,&b);
	gcd = GCD(a, b);
	printf("%d\n%d",gcd, a*b/gcd);
	return 0;
}