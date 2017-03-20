#include<iostream>
int a[101][101];
using namespace std;
int main()
{
	ios::sync_with_stdio(false); cin.tie(0);
	int n;
	cin >> n;
	while (n--) {
		int x, y;
		cin >> x >> y;
		for (int i = x; i < x + 10; i++) {
			for (int j = y; j < y + 10; j++) {
				if (!a[i][j] && i <= 100 && j <= 100) a[i][j] = 1;
			}
		}
	}
	int ans = 0;
	for (int i = 1; i <= 100; i++) {
		for (int j = 1; j <= 100; j++) {
			if (a[i][j] == 1) ans++;
		}
	}
	cout << ans;
	return 0;
}