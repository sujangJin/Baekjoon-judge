#include<iostream>
#include<vector>
#include<queue>

#define MAX 101
#define INF 987654321

using namespace std;

int n, m;
vector<pair<int, int>> adj[MAX];

int dijkstra(int node) {
	priority_queue<pair<int, int>> pq;
	vector<int> dist(MAX, INF);

	dist[node] = 0;
	pq.push(make_pair(0, node));
	while (!pq.empty()) {
		int min_dist = -1 * pq.top().first;
		int min_node = pq.top().second;
		pq.pop();

		for (int v = 0; v < adj[min_node].size(); v++) {
			int next_node = adj[min_node][v].first;
			// Runtime Error ¿øÀÎ
			int next_dist = min_dist + adj[min_node][v].second;
			if (next_dist < dist[next_node]) {
				dist[next_node] = next_dist;
				pq.push(make_pair(-1 * next_dist, next_node));
			}
		}
	}

	int ret = 0;
	for (int i = 1; i <= n; i++)
		ret += dist[i];
	return ret;
}

int main()
{
	int kevin;
	int min_kevin = INF, min_node;

	cin >> n >> m;
	for (int i = 0; i < m; i++)
	{
		int from, to;
		cin >> from >> to;
		adj[from].push_back(make_pair(to, 1));
		adj[to].push_back(make_pair(from, 1));
	}

	for (int v = 1; v <= n; v++)
	{
		kevin = dijkstra(v);
		if (kevin < min_kevin)
		{
			min_kevin = kevin;
			min_node = v;
		}
	}
	cout << min_node;
	return 0;
}
