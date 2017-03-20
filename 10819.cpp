#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
int main()
{
	int n, ans=0;
	scanf("%d",&n);
	vector<int> a(n);
	for (int i = 0; i < n; i++) scanf("%d", &a[i]);

	sort(a.begin(), a.end());

	do {
		int sum = 0;
		for (int i = 0; i < n-1; i++) {
			int tmp = a[i] - a[i+1];
			if (tmp < 0) tmp *= -1;
			sum += tmp;
		}
		ans = max(sum, ans);
	} while (next_permutation(a.begin(), a.end()));
	
	printf("%d",ans);
	return 0;
}