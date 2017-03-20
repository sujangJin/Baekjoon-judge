#include<cstdio>
const int MAX = 1e6;
int n, m, i, j, k;
int a[MAX + 1], b[MAX + 1], c[2 * MAX + 1];
int main()
{
	scanf("%d%d",&n,&m);
	for (int i = 0; i < n; i++) scanf("%d",a+i);
	for (int j = 0; j < m; j++) scanf("%d",b+j);
	while (i < n && j < m) {
		if (a[i] <= b[j]) c[k++] = a[i++];
		else c[k++] = b[j++];
	}
	while (i < n) c[k++] = a[i++];
	while (j < m) c[k++] = b[j++];

	for (int i = 0; i < n + m; i++) printf("%d ",c[i]);
	return 0;
}