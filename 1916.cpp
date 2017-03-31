#include <iostream>
#include <vector>
#include <queue>
using namespace std;
typedef pair<int,int> point;

#define MAXN 1001
// INF 를 8765432 로 했을 시 WA 가 나오기도 함
#define INF 987654321
int n,m;
int start,dest;
vector<point> adj[MAXN];
priority_queue<point> pq;

int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	
	cin >> n;
	cin >> m;
	for(int i=0;i<m;i++){
		int u,v,w;
		cin >> u >> v >> w;
		adj[u].push_back(make_pair(v,w));
	}
	cin >> start >> dest;
	vector<int> dist(n+1,INF);
	
	dist[start] = 0;
	pq.push(make_pair(start,0));
	while(!pq.empty()){
		int here = pq.top().first;
		int cost = -1 * pq.top().second;
		pq.pop();
		
		if(dist[here] < cost) continue;
		
		for(int i=0;i<adj[here].size();i++){
			int there = adj[here][i].first;
			int ncost = cost + adj[here][i].second;
			
			if(dist[there] > ncost){
				dist[there] = ncost;
				pq.push(make_pair(there, -1*ncost));
			}
		}
	}
	cout << dist[dest];
	return 0;
}