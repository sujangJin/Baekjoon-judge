#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<cstring>
using namespace std;
int n;
int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };
void bfs(int map[100][100], int height, int &val) {
	bool chk[100][100];
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (map[i][j] > height) chk[i][j] = false;
			else chk[i][j] = true;
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (!chk[i][j]) {
				val++;
				queue<pair<int, int>> q;
				q.push(make_pair(i, j));
				while (!q.empty()) {
					int x = q.front().first;
					int y = q.front().second;
					q.pop();
					if (chk[x][y]) continue;
					chk[x][y] = true;
					for (int i = 0; i < 4; i++) {
						int nx = x + dx[i];
						int ny = y + dy[i];
						if (nx >= 0 && nx < n && ny >= 0 && ny < n) {
							if (!chk[nx][ny]) {
								q.push(make_pair(nx, ny));
							}
						}
					}
				}
			}
		}
	}
}
int main()
{
	cin >> n;
	int max_val = 0;
	int map[100][100];
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> map[i][j];
			max_val = max(max_val, map[i][j]);
		}
	}

	int ans = 0;
	for (int h = 0; h <= max_val; h++) {
		int val = 0;
		bfs(map, h, val);
		ans = max(ans, val);
	}
	cout << ans;
	return 0;
}