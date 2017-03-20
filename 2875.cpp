#include<cstdio>
using namespace std;
int n, m, k, res;
int main()
{
	scanf("%d %d %d",&m,&n,&k);
	for (; m >= 2 && n >= 1 && m + n >= k + 3;) {
		res += 1;
		m -= 2;
		n -= 1;
	}
	printf("%d",res);
	return 0;
}