#include<iostream>
#include<cstring>
#include<queue>
using namespace std;
const int dx[] = { 1,-1,0,0,-1,1,-1,1 };
const int dy[] = { 0,0,1,-1,-1,1,1,-1 };
int map[51][51];
bool c[51][51];
int main()
{
	while (1) {
		int x, y, cnt = 0;
		queue<pair<int, int>> q;
		memset(map, 0, sizeof(map));
		memset(c, false, sizeof(c));
		cin >> y >> x;
		if (x == 0 && y == 0) break;

		for (int i = 1; i <= x; i++) {
			for (int j = 1; j <= y; j++) {
				cin >> map[i][j];
			}
		}

		for (int i = 1; i <= x; i++) {
			for (int j = 1; j <= y; j++) {
				if (map[i][j] == 1 && !c[i][j]) {
					cnt++;
					q.push({ i,j });
					c[i][j] = true;
					while (!q.empty()) {
						pair<int, int> now = q.front();
						q.pop();

						for (int i = 0; i < 8; i++) {
							int nx = now.first + dx[i];
							int ny = now.second + dy[i];
							if (nx >= 1 && nx <= x && ny >= 1 && ny <= y) {
								if (!c[nx][ny] && map[nx][ny] == 1) {
									c[nx][ny] = true;
									q.push({ nx,ny });
								}
							}
						}
					}
				}
			}
		}
		cout << cnt << "\n";
	}
	return 0;
}