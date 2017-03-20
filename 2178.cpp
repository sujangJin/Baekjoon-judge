#include<cstdio>
#include<queue>
using namespace std;
int a[101][101], res;
bool chk[101][101];
const int dx[] = { 0,1,-1,0 };
const int dy[] = { 1,0,0,-1 };
int n, m;
queue<pair<int, int>> q;
int main()
{
	scanf("%d %d", &n, &m);
	for (int i = 0; i<n; i++) {
		for (int j = 0; j<m; j++) {
			scanf("%1d", &a[i][j]);
		}
	}
	res = 1;
	chk[0][0] = true;
	q.push(make_pair(0, 0));
	while (!q.empty()) {
		int size = q.size();
		for (int i = 0; i < size; i++) {
			int x = q.front().first;
			int y = q.front().second;
			q.pop();
			if (x == n - 1 && y == m - 1) {
				printf("%ld",res);
				return 0;
			}
			for (int i = 0; i<4; i++) {
				int nx = x + dx[i];
				int ny = y + dy[i];
				if (nx < 0 || ny < 0 || nx >= n || ny >= y) continue;
				if (chk[nx][ny] || !a[nx][ny]) continue;
				chk[nx][ny] = true;
				q.push(make_pair(nx, ny));
			}
		}
		res++;
	}
	return 0;
}