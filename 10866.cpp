#include<cstdio>
using namespace std;
int main()
{
	int n, cnt=0;
	scanf("%d", &n);
	for (int i = 0, tmp; i < n; i++) {
		scanf("%d", &tmp);
		if (tmp == 1) cnt++;
	}
	if (cnt > n / 2)
		puts("Junhee is cute!");
	else
		puts("Junhee is not cute!");
	return 0;
}