#include<iostream>
#include<cstring>
using namespace std;
int n;
bool visited[100];
int g[100][100];
void dfs(int start, int num) {
	if (visited[num] == 1) return;
	visited[num] = true;
	g[start][num] = 1;
	for (int i = 0; i < n; i++) {
		if (g[num][i] == 1) dfs(start, i);
	}
}
int main()
{
	ios::sync_with_stdio(false);
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> g[i][j];
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (g[i][j] == 1) {
				memset(visited, 0, 100);
				dfs(i, j);
			}
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << g[i][j] << " ";
		}
		cout << "\n";
	}
	return 0;
}