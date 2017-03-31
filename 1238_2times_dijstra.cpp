#include<iostream>
#include<vector>
#include<queue>
using namespace std;
typedef pair<int, int> point;
#define INF 987654321
vector<point> adj[1001], adj2[1001];
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
		adj2[to].push_back(make_pair(from, val));
	}
	vector<vector<int>> dist(2, vector<int>(v + 1, INF));
	for (int q = 0; q < 2; q++)
	{
		dist[q][x] = 0;
		priority_queue<point> pq;
		pq.push(make_pair(x, 0));
		while (!pq.empty()) 
		{
			if (q == 0) 
			{
				int here = pq.top().first;
				int cost = -1 * pq.top().second;
				pq.pop();
				if (dist[q][here] > cost) continue;
				for (int i = 0; i < adj[here].size(); i++) 
				{
					int there = adj[here][i].first;
					int nextDist = cost + adj[here][i].second;
					if (dist[q][there] > nextDist) 
					{
						dist[q][there] = nextDist;
						pq.push(make_pair(there, -1 * nextDist));
					}
				}
			}
			else {
				int here = pq.top().first;
				int cost = -1 * pq.top().second;
				pq.pop();
				if (dist[q][here] > cost) continue;
				for (int i = 0; i < adj2[here].size(); i++) 
				{
					int there = adj2[here][i].first;
					int nextDist = cost + adj2[here][i].second;
					if (dist[q][there] > nextDist) 
					{
						dist[q][there] = nextDist;
						pq.push(make_pair(there, -1 * nextDist));
					}
				}
			}
		}
	}
	int ans = 0;
	for (int i = 1; i <= v; i++) 
	{
		if (ans < dist[0][i] + dist[1][i])
			ans = dist[0][i] + dist[1][i];
	}
	cout << ans;
	return 0;
}