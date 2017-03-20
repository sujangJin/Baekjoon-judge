#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
int n, res;
vector<int> a;
int main()
{
	scanf("%d", &n);
	while (n--) {
		int tmp = 0;
		scanf("%d", &tmp);
		a.push_back(tmp);
	}
	sort(a.begin(), a.end());
	int i = 1;
	for (int j = a.size() - 1; j >= 0; j--) {
		int comp = (i++) * a.at(j);
		res = max(comp, res);
	}
	printf("%d", res);
	return 0;
}