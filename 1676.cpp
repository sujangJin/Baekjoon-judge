#include<cstdio>
int a, res;
int main()
{
	scanf("%d", &a);
	for (int i = 5; i <= a; i *= 5) res += a / i;
	printf("%d", res);
	return 0;
}