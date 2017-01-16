#include<cstdio>
int n, k, idx, cnt;
int a[10];
int main()
{
	scanf("%d %d",&n,&k);
	for (int i = 0; i < n; i++) scanf("%d",a+i);
	for (; k > a[idx] && idx < n; idx++);
	while (k!=0) {
		if (k >= a[idx] && a[idx] != 0) {
			cnt += k /a[idx];
			k %= a[idx];
		}
		idx--; 
	}
	printf("%d",cnt);
	return 0;
}