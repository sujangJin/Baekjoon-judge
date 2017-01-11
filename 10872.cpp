#include<cstdio>
int a, res = 1;
int main()
{
	scanf("%d", &a);
	if (!a || a == 1) puts("1");
	else {
		for (int i = 1; i <= a; i++) res *= i;
		printf("%d", res);
	}
	return 0;
}