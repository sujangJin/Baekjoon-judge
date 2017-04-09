#include<iostream>
#include<vector>
#define INF 1e4
using namespace std;
int main()
{
	ios::sync_with_stdio(false); cin.tie(0);
	int n, m; cin >> n >> m;
	vector<vector<int>> adj(n + 1, vector<int>(n + 1, INF));
	vector<vector<int>> dist(n + 1, vector<int>(n + 1));
	
	// "자기자신 -> 자기자신" 은 거리가 0이라 둠 
	for (int i = 1; i <= n; i++) adj[i][i] = 0;
	
	for (int i = 0; i < m; i++) {
		int from, to;
		cin >> from >> to;
		adj[from][to] = 1;
		adj[to][from] = 1;
	}

	// dist 초기화, memcpy 사용하면 속도가 빨라진다고 함
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			dist[i][j] = adj[i][j];
		}
	}

	// floyd
	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (dist[i][k] + dist[k][j] < dist[i][j]) {
					dist[i][j] = dist[i][k] + dist[k][j];
				}
			}
		}
	}

	// output ans[i] : 각 노드에서 i번째 노드로 도착하는 경로의 합
	vector<int> ans(n + 1);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (dist[i][j] != INF) ans[i] += dist[i][j];
		}
	}

	int minVal = INF;
	int minNum;
	for (int i = 1; i <= n; i++) {
		if (ans[i] < minVal) {
			minVal = ans[i];
			minNum = i;
		}
	}

	cout << minNum;
	return 0;
}