#include<cstdio>
#include<algorithm>
using namespace std;
unsigned int n, t;
int mset = 1000, meach = 1000;
int main()
{
	scanf("%u %u", &n, &t);
	if (n > 100 || t > 50) return 0;
	while (t--) {
		unsigned int tmp_set, tmp_each;
		scanf("%u %u", &tmp_set, &tmp_each);
		mset = min((int)tmp_set, mset);
		meach = min((int)tmp_each, meach);
	}
	if (n > 6) {
		int res = 0;
		while (n != 0) {
			if (n > 6) {
				if (mset < meach * 6) res += mset;
				else res += meach * 6;
				n -= 6;
			}
			else {
				if (mset < meach * n) res += mset;
				else res += meach * n;
				n = 0;
			}
		}
		printf("%d",res);
	} 
	else printf("%d", mset < meach*n ? mset : meach*n);
	return 0;
}