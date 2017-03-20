#include<cstdio>
#include<algorithm>
using namespace std;
int main()
{
	int e, s, m;
	scanf("%d %d %d",&e,&s,&m);
	int cnt = 1;
	int cnt_e = 1; // 15
	int cnt_s = 1; // 28
	int cnt_m = 1; // 19
	while (1) {
		if (e == cnt_e && s == cnt_s && m == cnt_m) break;
		cnt++;
		cnt_e++; if (cnt_e == 16) cnt_e = 1;
		cnt_s++; if (cnt_s == 29) cnt_s = 1;
		cnt_m++; if (cnt_m == 20) cnt_m = 1;
	}
	printf("%d",cnt);
	return 0;
}