#include<cstdio>
#include<cstring>
using namespace std;
bool digit[10];
int main()
{
	long long n;
	while (~scanf("%lld", &n)) {
		memset(digit, false, sizeof(digit));
		int cnt = 0;
		int k = 1;
		while (1) {
			long long now = k * n;
			while (now >= 10) {
				if (!digit[now % 10]) {
					cnt++;
					digit[now % 10] = true;
				}
				if (cnt == 10) break;
				else now /= 10;
			}
			if (now < 10 && !digit[now]) {
				cnt++;
				digit[now] = true;
			}
			if (cnt == 10) break;
			else k++;
		}
		printf("%d\n", k);
	}
	return 0;
}