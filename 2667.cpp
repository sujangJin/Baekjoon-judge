#include<cstdio>
#include<queue>
#include<algorithm>
using namespace std;
queue<pair<int,int>> q;
const int dx[] = { 0,0,1,-1 };
const int dy[] = { 1,-1,0,0 };
int n;
int res[400], cnt;
int a[25][25];
bool chk[25][25];
void bfs(int x,int y) {
	if (chk[x][y]) return;
	chk[x][y] = true;
	q.push(make_pair(x, y));
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		cnt++;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx >= 0 && ny >= 0 && nx < n && ny < n) {
				if (a[nx][ny] == 1 && !chk[nx][ny]) {
					chk[nx][ny] = true;
					q.push(make_pair(nx, ny));
				}
			}
		}
	}
}
int main()
{
	//input
	scanf("%d",&n);
	if (n < 5 || n > 25) return 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			scanf("%1d", &a[i][j]);
		}
	}
	//process
	int idx = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (a[i][j] == 1 && !chk[i][j]) {
				cnt = 0;
				bfs(i, j);
				res[idx++] = cnt;
			}
		}
	}
	sort(res, res + idx);
	//outout
	printf("%d\n",idx);
	for (int i = 0; i < idx; i++) printf("%d\n",res[i]);
	return 0;
}