#include<iostream>
using namespace std;
int t;
int a[51][51];
const int dx[] = { 0,0,-1,1 };
const int dy[] = { -1,1,0,0 };
bool chk[51][51];
void dfs(int x, int y, int size_x, int size_y) {
	chk[x][y] = true;
	for (int i = 0; i < 4; i++) {
		int next_x = x + dx[i];
		int next_y = y + dy[i];
		if (next_x >= 0 && next_y >= 0 && next_x < size_x && next_y < size_y) {
			if (!chk[next_x][next_y] && a[next_x][next_y] == 1) {
				chk[next_x][next_y] = true;
				dfs(next_x, next_y, size_x, size_y);
			}
		}
	}
}
int main()
{
	ios::sync_with_stdio(false); cin.tie(0);
	cin >> t;
	while (t--) {
		int n, m, k;
		int cnt = 0;
		cin >> n >> m >> k;
		for (int i = 0, x, y; i < k; i++) {
			cin >> x >> y;
			a[x][y] = 1;
		}

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (a[i][j] == 1 && !chk[i][j]) {
					dfs(i, j, n, m);
					cnt++;
				}
			}
		}
		printf("%d\n", cnt);

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				chk[i][j] = false;
				a[i][j] = 0;
			}
		}
	}
	return 0;
}