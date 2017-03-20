#include<cstdio>
void hanoi(int n, int x, int y) {
	if (n == 0) return;
	hanoi(n - 1, x, 6 - x - y);
	printf("%d %d\n",x,y);
	hanoi(n - 1, 6 - x - y, y);
}
int n;
int main()
{
	scanf("%d",&n);
	// pow(2,n) == 1<<n //
	printf("%d\n",(1<<n)-1);
	hanoi(n, 1, 3);
	return 0;
}