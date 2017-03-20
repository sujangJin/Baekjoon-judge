#include<cstdio>
#include<queue>
using namespace std;
int n, m;
int a[1000][1000];
bool chk[1000][1000][2];
int dist[1000][1000];
const int dx[] = { 0,0,1,-1 };
const int dy[] = { 1,-1,0,0 };

typedef struct TYPE{
	int x, y;
	int wall_cnt, move;
	TYPE(int a, int b, int c, int d) {
		x = a; y = b; wall_cnt = c; move = d;
	}
}TYPE;

int main()
{
	scanf("%d %d",&n,&m);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf("%1d",&a[i][j]);
		}
	}
	queue<TYPE> q;
	chk[0][0][0] = true;
	q.push(TYPE(0,0,0,1));
	while (!q.empty()) {
		TYPE now = q.front();
		q.pop();
		if (now.x == n-1 && now.y == m-1) {
			printf("%d",now.move);
			return 0;
		}
		for (int i = 0; i < 4; i++) {
			int nx = now.x + dx[i];
			int ny = now.y + dy[i];
			if (now.wall_cnt == 0) {
				if (nx >= 0 && nx < n && ny >= 0 && ny < m) {
					if (!chk[nx][ny][0] && a[nx][ny] == 0) {
						chk[nx][ny][0] = true;
						q.push(TYPE(nx, ny, 0, now.move + 1));
					}
					else if (!chk[nx][ny][1] && a[nx][ny] == 1) {
						chk[nx][ny][1] = true;
						q.push(TYPE(nx, ny, 1, now.move + 1));
					}
				}
			}
			else if (now.wall_cnt == 1) {
				if (nx >= 0 && nx < n && ny >= 0 && ny < m) {
					if (!chk[nx][ny][1] && a[nx][ny] == 0) {
						chk[nx][ny][1] = true;
						q.push(TYPE(nx, ny, 1, now.move + 1));
					}
				}
			}
		}
	}
	return 0;
}