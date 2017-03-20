#include<cstdio>
#include<queue>
using namespace std;
const int dx[] = {-2,-1,1,2,2,1,-1,-2};
const int dy[] = {1,2,2,1,-1,-2,-2,-1};
int t,l;
int a[300][300];
queue<pair<int, int>> q;
int main()
{
	scanf("%d",&t);
	while (t--) {
		int st_x, st_y;
		int end_x, end_y;
		//input
		scanf("%d",&l);
		if (l < 4 || l > 300) return 0;
		scanf("%d %d", &st_x, &st_y);
		scanf("%d %d", &end_x, &end_y);
		//process
		a[st_x][st_y] = 1;
		q.push({ st_x,st_y });
		while (!q.empty()) {
			int x = q.front().first;
			int y = q.front().second;
			q.pop();
			for (int i = 0; i < 8; i++) {
				int nx = x + dx[i];
				int ny = y + dy[i];
				if (nx >= 0 && ny >= 0 && nx < l && ny < l) {
					if (a[nx][ny] == 0) {
						a[nx][ny] = a[x][y] + 1;
						q.push({ nx,ny });
					}
				}
			}
		}
		//output
		printf("%d\n",a[end_x][end_y]-1);
		//reinitialize
		for (int i = 0; i < l; i++) {
			for (int j = 0; j < l; j++) {
				a[i][j] = 0;
			}
		}
		l = 0;
	}
	return 0;
}