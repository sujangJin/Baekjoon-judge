#include<cstdio>
bool broken[10]; //��ư ���� TF
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
	for (int i = 0; i <= 1000000; i++) { // ���� ��ư���� �̵��ϴ� ä��
		int len = possible(i); // ���̸� ���
		if (len > 0) {
			int press = i - n; // + �� - �� �� �� ������ �ϴ��� ���
			if (press < 0) press *= -1;
			if (ans > len + press) ans = len + press;
		}
	}
	printf("%d",ans);
	return 0;
}