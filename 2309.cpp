#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
vector<int> a;
int main()
{
	int tmp, sum = 0;
	while (~scanf("%d", &tmp)) {
		a.push_back(tmp);
		sum += tmp;
	}
	sort(a.begin(), a.end());

	for (int i = 0; i < a.size(); i++) {
		for (int j = i + 1; j < a.size(); j++) {
			if (sum - a[i] - a[j] == 100) {
				for (int k = 0; k < a.size(); k++) {
					if (i == k || j == k) continue;
					printf("%d\n", a[k]);
				}
			}
		}
	}
	return 0;
}