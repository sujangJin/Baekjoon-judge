#include<iostream>
#include<cstring>
#include<vector>

using namespace std;

vector<vector<int>> map(300, vector<int>(300, 0));
bool visit[300][300];
int n,m;

int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };

vector<vector<int>> melting_process() {
	vector<vector<int>> res(300, vector<int>(300, 0));
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			if (map[i][j] == 0) continue;
			int adjacent = 0;
			for (int k = 0; k < 4; ++k) {
				int ni = i + dx[k];
				int nj = j + dy[k];
				if (ni < 0 || nj < 0 || ni >= n || nj >= m) continue;
				if (map[ni][nj] == 0) adjacent++;
			}
			res[i][j] = map[i][j] - adjacent;
			if (res[i][j] < 0) res[i][j] = 0;
		}
	}
	return res;
}

void dfs(int x, int y) {
	for (int i = 0; i < 4; ++i) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
		if (map[nx][ny] != 0 && !visit[nx][ny]) {
			visit[nx][ny] = true;
			dfs(nx, ny);
		}
	}
}

bool is_empty_ice() {
	bool res = true;
	for (int i = 0; i < m; ++i) {
		for (int j = 0; j < n; ++j) {
			if (map[i][j] != 0) {
				res = false;
				break;
			}
		}
	}
	return res;
}
int main()
{
	ios::sync_with_stdio(false); cin.tie(0);
	cin >> n >> m;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			cin >> map[i][j];
		}
	}

	int res = 0;
	while (1) {
		map = melting_process();
		if (is_empty_ice()) {
			cout << 0;
			return 0;
		}
		int group = 0;
		memset(visit, false, sizeof(visit));
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < m; ++j) {
				if (map[i][j] != 0 && !visit[i][j]) {
					visit[i][j] = true;
					dfs(i, j);
					group++;
				}
			}
		}
		res++;
		if (group >= 2) break;
	}
	cout << res;
	return 0;
}