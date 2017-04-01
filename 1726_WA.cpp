#include <iostream>
#include <queue>
#include <deque>
#include <tuple>
#include <algorithm>
#include <cstring>
using namespace std;
int dirx[] = { 0,0,1,-1 };
int diry[] = { 1,-1,0,0 };
int map[101][101];
int dist[101][101];
int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	int m, n;
	cin >> m >> n;
	for (int i = 1; i <= m; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> map[i][j];
		}
	}
	int stx, sty, sdir, edx, edy, edir;
	cin >> stx >> sty >> sdir;
	cin >> edx >> edy >> edir;
	sdir--, edir--;
	deque<tuple<int, int, int>> deq;
	memset(dist, -1, sizeof(dist));
	deq.push_front(make_tuple(stx, sty, sdir));
	dist[stx][sty] = 0;
	while (!deq.empty()) {
		int x = get<0>(deq.front());
		int y = get<1>(deq.front());
		int dir = get<2>(deq.front());
		deq.pop_front();
		if (x == edx && y == edy) {
			int ans = dist[x][y];
			
			if (dir == 0) {
				if (edir == 2 || edir == 3) ans++;
				else if (edir == 1) ans += 2;
			}
			else if (dir == 1) {
				if (edir == 2 || edir == 3) ans++;
				else if (edir == 0) ans += 2;
			}
			else if (dir == 2) {
				if (edir == 0 || edir == 1) ans++;
				else if (edir == 3) ans += 2;
			}
			else {
				if (edir == 0 || edir == 1) ans++;
				else if (edir == 2) ans += 2;
			}
			
			cout << ans;
			return 0;
		}

		//현재 방향으로 3칸
		for (int i = 1; i <= 3; i++) {
			int nx = x + i * dirx[dir];
			int ny = y + i * diry[dir];
			if (nx >= 1 && ny >= 1 && nx <= m && ny <= n) {
				if (map[nx][ny] == 0) {
					if (dist[nx][ny] == -1) {
						dist[nx][ny] = dist[x][y] + 1;
						deq.push_back(make_tuple(nx, ny, dir));
					}
					else {
						if (dist[nx][ny] > dist[x][y] + 1) {
							dist[nx][ny] = dist[x][y] + 1;
							deq.push_front(make_tuple(nx, ny, dir));
						}
					}
					
				}
				else break;
			}
		}

		int rotate90[2];
		if (dir == 0 || dir == 1) {
			rotate90[0] = 2;
			rotate90[1] = 3;
		}
		else {
			rotate90[0] = 0;
			rotate90[1] = 1;
		}

		// 90도 회전한 방향으로 3칸
		for (int ndir : rotate90) {
			for (int i = 1; i <= 3; i++) {
				int nx = x + i * dirx[ndir];
				int ny = y + i * diry[ndir];
				if (nx >= 1 && ny >= 1 && nx <= m && ny <= n) {
					if (map[nx][ny] == 0) {
						if (dist[nx][ny] == -1) {
							dist[nx][ny] = dist[x][y] + 2;
							deq.push_back(make_tuple(nx, ny, ndir));
						}
						else {
							if (dist[nx][ny] > dist[x][y] + 2) {
								dist[nx][ny] = dist[x][y] + 2;
								deq.push_front(make_tuple(nx, ny, ndir));
							}
						}

					}
					else break;
				}
			}
		}

		
		// 180도 회전한 방향
		for (int i = 1; i <= 3; i++) {
			int ndir;
			if (dir == 1) ndir = 0;
			else if (dir == 0) ndir = 1;
			else if (dir == 2) ndir = 3;
			else ndir = 2;
			int nx = x + i * dirx[ndir];
			int ny = y + i * diry[ndir];
			if (nx >= 1 && ny >= 1 && nx <= m && ny <= n) {
				if (map[nx][ny] == 0) {
					if (dist[nx][ny] == -1) {
						dist[nx][ny] = dist[x][y] + 3;
						deq.push_back(make_tuple(nx, ny, ndir));
					}
					else {
						if (dist[nx][ny] > dist[x][y] + 3) {
							dist[nx][ny] = dist[x][y] + 3;
							deq.push_front(make_tuple(nx, ny, ndir));
						}
					}

				}
				else break;
			}
		}
	}
	return 0;
}