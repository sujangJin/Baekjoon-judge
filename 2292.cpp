#include<cstdio>
long long a;
int res;
const int MAX = 1e9;
int main()
{
	scanf("%lld",&a);
	if (a < 1) return 0;
	for (int i = 1;; i++) {
		if (3 * i * (i - 1) + 1 >= a) {
			res = i;
			break;
		}
	}
	printf("%d",res);
	return 0;
}