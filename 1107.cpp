#include<cstdio>
bool broken[10]; //버튼 상태 TF
int n, m, ans;
int possible(int c) {
	if (c == 0) {
		if (broken[0]) return 0;
		else return 1;
	}
	int len = 0;
	while (c > 0) {
		if (broken[c % 10]) return 0;
		len++;
		c /= 10;
	}
	return len;
}
int main()
{
	scanf("%d %d",&n,&m);
	for (int i = 0; i < m; i++) {
		int c;
		scanf("%d",&c);
		broken[c] = true;
	}
	ans = n - 100;
	if (ans < 0) ans *= -1;
	for (int i = 0; i <= 1000000; i++) { // 숫자 버튼으로 이동하는 채널
		int len = possible(i); // 길이를 잰다
		if (len > 0) {
			int press = i - n; // + 나 - 를 몇 번 눌러야 하는지 계산
			if (press < 0) press *= -1;
			if (ans > len + press) ans = len + press;
		}
	}
	printf("%d",ans);
	return 0;
}