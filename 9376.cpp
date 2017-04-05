#include<iostream>
#include<string>
#include<cstring>
#include<vector>
#include<queue>
#include<tuple>

using namespace std;
int h, w;
vector<vector<int>> bfs(const vector<string> &map, int st, int ed, int st_cnt) {
	vector<vector<int>> ans(h + 2, vector<int>(w + 2));
	bool c[101][101];
	const int dx[] = { 0,0,1,-1 };
	const int dy[] = { 1,-1,0,0 };

	for (int i = 0; i < h + 2; i++) {
		for (int j = 0; j < w + 2; j++) {
			ans[i][j] = -1;
		}
	}

	queue<tuple<int, int, int>> q;
	q.push(tie(st, ed, st_cnt));
	ans[st][ed] = 0;
	while (!q.empty()) {
		int x, y, cnt;
		tie(x, y, cnt) = q.front();
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			int ncnt = ans[x][y];

			if (nx < 0 || ny < 0 || nx >= h + 2 || ny >= w + 2) continue;
			if (map[nx][ny] == '#') ncnt++;

			if (map[nx][ny] == '*') continue;
			if (ncnt < ans[nx][ny] || ans[nx][ny] == -1) {
				ans[nx][ny] = ncnt;
				q.push(tie(nx, ny, ncnt));
			}
		}
	}
	return ans;
}
void print(const vector<vector<int>> &a) {
	for (int i = 0; i < a.size(); i++) {
		for (int j = 0; j < a[i].size(); j++) {
			cout << a[i][j] << "   ";
		}
		cout << '\n';
	}
}

int main()
{
	ios::sync_with_stdio(false); cin.tie(0);
	int tc; cin >> tc;
	while (tc--) {
		cin >> h >> w;
		vector<string> map(h + 2);
		for (int i = 1; i <= h; i++) {
			cin >> map[i];
			map[i] = '.' + map[i] + '.';
		}

		for (int i = 0; i < w + 2; i++) {
			map[0] += '.';
			map[h + 1] += '.';
		}

		vector<vector<int>> sanggeun = bfs(map, 0, 0, 0);
		vector<pair<int, int>> prison_location;

		for (int i = 0; i < h + 2; i++) {
			for (int j = 0; j < w + 2; j++) {
				if (map[i][j] == '$') prison_location.push_back({ i,j });
			}
		}
		vector<vector<int>> prison1 = bfs(map, prison_location.at(0).first, prison_location.at(0).second, 0);
		vector<vector<int>> prison2 = bfs(map, prison_location.at(1).first, prison_location.at(1).second, 0);
/*		print(sanggeun);
		cout << '\n';
		print(prison1);
		cout << '\n';
		print(prison2);
		cout << '\n';
*/

		int door_cnt = (h + 2)*(w + 2);
		for (int i = 0; i < h + 2; i++) {
			for (int j = 0; j < w + 2; j++) {
				if (map[i][j] != '*') {
					if (sanggeun[i][j] == -1 || prison1[i][j] == -1 || prison2[i][j] == -1) continue;
					int tmp = sanggeun[i][j] + prison1[i][j] + prison2[i][j];
					if (map[i][j] == '#') tmp -= 2;
					if (door_cnt > tmp) {
						door_cnt = tmp;
					}
				}
			}
		}
		cout << door_cnt << '\n';

	}

	return 0;
}