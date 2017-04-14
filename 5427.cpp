#include<iostream>
#include<queue>
#include<vector>
#include<string>
#include<cstring>
#include<deque>
using namespace std;
int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };
int dist[1001][1001];
int main()
{
	ios::sync_with_stdio(false); cin.tie(0);
	int tc; cin >> tc;
	for (int i = 0; i < tc; i++) {
		int w, h;
		cin >> w >> h;
		vector<string> map(h);
		for (int i = 0; i < h; i++) cin >> map[i];
		deque<pair<int, int>> dq, user;
		memset(dist, -1, sizeof(dist));
		int stx, sty;
		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				if (map[i][j] == '@')
					stx = i, sty = j;
				else if (map[i][j] == '*') {
					dq.push_back(make_pair(i, j));
				}
			}
		}

		user.push_back(make_pair(stx, sty));
		dist[stx][sty] = 0;
		while (!user.empty()) {
			int size = dq.size();
			for (int i = 0; i < size; i++) {
				auto now = dq.front();
				dq.pop_front();
				for (int i = 0; i < 4; i++) {
					int nx = now.first + dx[i];
					int ny = now.second + dy[i];
					if (nx < 0 || ny < 0 || nx >= h || ny >= w) continue;
					if (map[nx][ny] == '.' || map[nx][ny] == '@') {
						map[nx][ny] = '*';
						dq.push_back(make_pair(nx, ny));
					}
				}
			}

			
			int size_user = user.size();
			for (int i = 0; i < size_user; i++) {
				int x = user.front().first;
				int y = user.front().second;
				user.pop_front();
				for (int i = 0; i < 4; i++) {
					int nx = x + dx[i];
					int ny = y + dy[i];
					if (nx < 0 || ny < 0 || nx >= h || ny >= w) continue;
					if (map[nx][ny] == '*' || map[nx][ny] == '#') continue;
					if (map[nx][ny] == '.' && dist[nx][ny] == -1) {
						dist[nx][ny] = dist[x][y] + 1;
						user.push_back(make_pair(nx, ny));
					}
				}
			}
		}

		int res = h*w;
		for (int i = 0, j = 0; i < h; i++) {
			if (dist[i][j] == -1) continue;
			if (res > dist[i][j]) res = dist[i][j];
		}
		for (int i = 0, j = 0; j < w; j++) {
			if (dist[i][j] == -1) continue;
			if (res > dist[i][j]) res = dist[i][j];
		}
		for (int i = h - 1, j = 0; j < w; j++) {
			if (dist[i][j] == -1) continue;
			if (res > dist[i][j]) res = dist[i][j];
		}
		for (int i = 0, j = w - 1; i < h; i++) {
			if (dist[i][j] == -1) continue;
			if (res > dist[i][j]) res = dist[i][j];
		}
		if (res == h*w) cout << "IMPOSSIBLE";
		else cout << res + 1;
		cout << '\n';
	}
	return 0;
}