#include<cstdio>
#include<algorithm>
using namespace std;
int a[100000];
int n, m;
int main()
{
	scanf("%d", &n);
	for (int i = 0; i<n; i++) scanf("%d", a + i);
	scanf("%d", &m);
	sort(a, a + n);
	while (m--) {
		int tmp, res = 0;
		scanf("%d", &tmp);
		int left = 0;
		int right = n - 1;
		while (left <= right) {
			int mid = (left + right) / 2;
			if (tmp > a[mid]) {
				left = mid + 1;
			}
			else if (tmp < a[mid]) {
				right = mid - 1;
			}
			else {
				res++;
				break;
			}
		}
		printf("%d\n", res);
	}
	return 0;
}