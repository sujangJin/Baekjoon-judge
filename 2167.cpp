#include<iostream>
using namespace std;
int d[301][301];
int n, m, k;
int main()
{
	ios::sync_with_stdio(false); cin.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			int tmp;
			cin >> tmp;
			d[i][j] = d[i - 1][j] + d[i][j - 1] - d[i - 1][j - 1] + tmp;
		}
	}
	cin >> k;
	while (k--) {
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		cout << d[x2][y2] - d[x1 - 1][y2] - d[x2][y1 - 1] + d[x1 - 1][y1 - 1] << "\n";
	}
	return 0;
}