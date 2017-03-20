#include<cstdio>
#include<algorithm>
using namespace std;
int pos[10001], neg[10001], pos_cnt, neg_cnt;
int zero, one, res;
int main()
{
	int n;
	scanf("%d",&n);
	if (n >= 10000) return 0;
	while (n--) {
		int tmp; scanf("%d", &tmp);
		if (tmp > 1) { pos[tmp]++; pos_cnt++; }
		else if (tmp < 0) { neg[-tmp]++; neg_cnt++; }
		else if (tmp == 1) one++;
		else zero++;
	}
	int save = 0, cnt = 0;
	for (int i = 10000; i >= 2; i--) {
		if (pos[i] >= 2) {
			res += i*i;
			pos[i] -= 2;
			i++;
		}
		else if (pos[i] == 1) {
			if (cnt == 1) {
				res += i * save;
				save = 0; cnt = 0;
			}
			else {
				cnt++;
				save = i;
			}
		}
	}
	if (cnt == 1) res += save;
	cnt = 0; save = 0;
	for (int i = 10000; i >= 1; i--) {
		if (neg[i] >= 2) {
			res += i*i;
			neg[i] -= 2;
			i++;
		}
		else if (neg[i] == 1) {
			if (cnt == 1) {
				res += i * save;
				save = 0; cnt = 0;
			}
			else {
				cnt++;
				save = i;
			}
		}
	}
	if (cnt == 1 && zero == 0) res -= save;
	printf("%d",res+one);
	return 0;
}