#include<cstdio>
#include<algorithm>
using namespace std;
int n, p[1000], res;
int main()
{
	scanf("%d",&n);
	for (int i = 0; i < n; i++) scanf("%d",p+i);
	sort(p, p + n);
	int now = 0;
	for (int i = 0; i < n; i++) {
		now += p[i];
		res += now;
	}
	printf("%d",res);
	return 0;
}