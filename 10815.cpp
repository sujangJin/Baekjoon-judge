#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
int n, m;
int main()
{
	scanf("%d",&n);
	vector<int> a(n);
	for (int i = 0; i < n; i++) scanf("%d ", &a[i]);
	
	sort(a.begin(), a.end());
	scanf("%d",&m);
	while (m--) {
		int tmp;
		scanf("%d",&tmp);
		int l = 0;
		int r = n - 1;
		bool exist = false;
		while (l <= r) {
			int mid = (l + r) / 2;
			if (tmp > a[mid]) l = mid + 1;
			else if (tmp == a[mid]) {
				exist = true; 
				break;
			}
			else r = mid - 1;
		}
		printf("%d ",exist);
	}
	return 0;
}