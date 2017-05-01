#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
char map[20][20];

int dx[] = { 1,-1,0,0 };
int dy[] = { 0,0,1,-1 };

int n, m;
int res;

void dfs(int x, int y, int cnt, bool set[25]) {
	res = max(res, cnt);
	for (int i = 0; i<4; ++i) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx<0 || ny<0 || nx >= n || ny >= m) continue;
		if (set[map[nx][ny] - 'A']) continue;
		set[map[nx][ny] - 'A'] = true;
		dfs(nx, ny, cnt+1, set);
		set[map[nx][ny] - 'A'] = false;
	}
	res = max(res, cnt);
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	cin >> n >> m;
	for (int i = 0; i<n; ++i) {
		for (int j = 0; j<m; ++j) {
			cin >> map[i][j];
		}
	}

	bool alpha_set[25];
	memset(alpha_set, false, sizeof(alpha_set));

	alpha_set[map[0][0] - 'A'] = true;
	dfs(0, 0, 1, alpha_set);
	cout << res;
	return 0;
}