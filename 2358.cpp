#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
bool map[100][100];
int m, n, k;
void bfs(int x, int y, int &cnt) {
	int dx[] = { 0,0,1,-1 };
	int dy[] = { 1,-1,0,0 };
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx >= 0 && nx < m && ny >= 0 && ny < n) {
			if (!map[nx][ny]) {
				map[nx][ny] = true;
				cnt++;
				bfs(nx, ny, cnt);
			}
		}
	}

}
int main()
{
	ios::sync_with_stdio(false); cin.tie(0);
	cin >> m >> n >> k;
	for (int i = 0,sx,sy,ex,ey; i < k; i++) {
		cin >> sy >> sx >> ey >> ex;
		for (int x = sx; x < ex; x++) {
			for (int y = sy; y < ey; y++) {
				if(!map[x][y]) map[x][y] = true;
			}
		}
	}

	//Å½»ö
	vector<int> ans;
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (!map[i][j]) {
				int val = 0;
				bfs(i, j, val);
				if (val == 0) val++;
				ans.push_back(val);
			}
		}
	}
	sort(ans.begin(), ans.end());
	cout << ans.size() << '\n';
	for (int i = 0; i < ans.size(); i++)
		cout << ans[i] << " ";

	return 0;
}