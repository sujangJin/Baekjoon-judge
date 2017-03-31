#include <iostream>
#include <vector>
#include <queue>
using namespace std;
typedef pair<int,int> point;

#define INF 999999
int v,e,start;
vector<point> adj[20001];

vector<int> dijkstra(int src){
	vector<int> dist(v+1, INF);
	dist[src] = 0;
	priority_queue<point> pq;
	pq.push(make_pair(src,0));
	while(!pq.empty()){
		int here = pq.top().first;
		int cost = -1 * pq.top().second;
		pq.pop();
		if(dist[here] < cost) continue;
		for(int i=0; i<adj[here].size(); i++){
			int there = adj[here][i].first;
			int ndist = cost + adj[here][i].second;
			if(dist[there] > ndist){
				dist[there] = ndist;
				pq.push(make_pair(there, -1*ndist));
			}
		}
	}
	return dist;
}

int main()
{
	ios::sync_with_stdio(false); cin.tie(0);
	cin >> v >> e >> start;
	for(int i=0;i<e;i++){
		int s,e,w;
		cin >> s >> e >> w;
		adj[s].push_back(make_pair(e,w));
	}
	vector<int> ans = dijkstra(start);
	
	for(int i=1;i<ans.size();i++){
		if(ans[i] == INF){
			cout << "INF" << '\n';
		} else{
			cout << ans[i] << '\n';
		}
	}
	return 0;
}