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
	// �ߺ� ������ ������ dp
	// 13,14���� for���� �����ϸ� �ߺ� ����� dp �� �ȴ�.
	// �������� ���� for���� ���󰡺���..
	// d[3] = d[1]+d[2] �ε�
	// �̴� d[2] = d[0] + d[1] �̹Ƿ� d[1]�� �ߺ��ȴ�.
	for (int j = 0; j < n; j++) {
		for (int i = 1; i <= k; i++) {
			if(i-a[j] >= 0)	d[i] += d[i - a[j]];
		}
	}
	printf("%d",d[k]);
	return 0;
}