#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
vector<int> a;
int tmp, res;
int main()
{
	while (~scanf("%1d", &tmp)) {
		a.push_back(tmp);
		res +=  tmp;
	}
	sort(a.begin(), a.end());
	if (a[0] == 0 && res % 3 == 0) {
		for (int i = a.size() - 1; i >= 0; i--) printf("%d",a.at(i));
	}
	else {
		puts("-1");
	}
	return 0;
}