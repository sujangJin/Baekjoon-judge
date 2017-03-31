#include<iostream>
#include<vector>
#include<queue>
using namespace std;
typedef pair<int, int> point;
#define INF 987654321
vector<point> adj[1001];
vector<int> dijkstra(int src, int v, int e) 
{
	vector<int> dist(v + 1, INF);
	dist[src] = 0;
	priority_queue<point> pq;
	pq.push(make_pair(src, 0));
	while (!pq.empty()) 
	{
		int here = pq.top().first;
		int cost = -1 * pq.top().second;
		pq.pop();
		if (dist[here] < cost) continue;
		for (int i = 0; i < adj[here].size(); i++) 
		{
			int there = adj[here][i].first;
			int nextDist = cost + adj[here][i].second;
			if (dist[there] > nextDist) 
			{
				dist[there] = nextDist;
				pq.push(make_pair(there, -1 * nextDist));
			}
		}
	}
	return dist;
}
int main()
{
	ios::sync_with_stdio(false); cin.tie(0);
	int v, e, x;
	cin >> v >> e >> x;
	for (int i = 0; i < e; i++) 
	{
		int from, to, val;
		cin >> from >> to >> val;
		adj[from].push_back(make_pair(to, val));
	}
	int ans = 0;
	vector<int> come = dijkstra(x, v, e);
	for (int start = 1; start <= v; start++) 
	{
		vector<int> go = dijkstra(start, v, e);
		if (ans < go[x] + come[start]) 
			ans = go[x] + come[start];
	}
	cout << ans;
	return 0;
}