#include <cstdio>
#include <map>
using namespace std;
map<int, int> mp;
int main()
{
	int n;
	scanf("%d", &n);
	while (n--)
	{
		int t;
		scanf("%d", &t);
		mp[t]++;
	}

	int m;
	scanf("%d", &m);
	while (m--)
	{
		int t;
		scanf("%d", &t);
		printf("%d ", mp[t]);
	}
	return 0;
}