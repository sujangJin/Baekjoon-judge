#include<cstdio>
int a,idx=2;
int main()
{
	scanf("%d",&a);
	if (a == 1) return 0;
	while (idx*idx <= a) {
		if (a%idx == 0) {
			printf("%d\n",idx);
			a /= idx;
		}
		else idx++;
	}
	if (a > 1) printf("%d\n",a);
	return 0;
}