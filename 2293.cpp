#include<cstdio>
using namespace std;
int a[101];
int d[10001];
int main()
{
	int n, k;
	scanf("%d %d", &n, &k);
	for (int i = 0; i < n; i++) scanf("%d", a + i);
	d[0] = 1;
	// 중복 제거한 상태의 dp
	// 13,14줄의 for문을 변경하면 중복 허용한 dp 가 된다.
	// 변경했을 때의 for문을 따라가보면..
	// d[3] = d[1]+d[2] 인데
	// 이는 d[2] = d[0] + d[1] 이므로 d[1]이 중복된다.
	for (int j = 0; j < n; j++) {
		for (int i = 1; i <= k; i++) {
			if(i-a[j] >= 0)	d[i] += d[i - a[j]];
		}
	}
	printf("%d",d[k]);
	return 0;
}