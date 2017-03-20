#include<iostream>
#include<queue>
#include<algorithm>
using namespace std;
int n, m;
int a[1000][1000];
int dist1[1000][1000];
int dist2[1000][1000];
int res[1000][1000];
int main()
{
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> a[i][j];
		}
	}
	res[0][0] = a[0][0];
	for (int i = 1; i < m; i++)
		res[0][i] = res[0][i-1] + a[0][i];

	for (int i = 1; i < n; i++) {
		// left -> right
		dist1[i][0] = res[i - 1][0] + a[i][0];
		for (int j = 1; j < m; j++)
			dist1[i][j] = max(dist1[i][j - 1], res[i - 1][j]) + a[i][j];
		// right -> left
		dist2[i][m - 1] = res[i - 1][m - 1] + a[i][m-1];
		for (int j = m - 2; j >= 0; j--)
			dist2[i][j] = max(dist2[i][j + 1], res[i - 1][j]) + a[i][j];
		// max value
		for (int j = 0; j < m; j++)
			res[i][j] = max(dist1[i][j], dist2[i][j]);
	}
	printf("%d", res[n - 1][m - 1]);
	return 0;
}