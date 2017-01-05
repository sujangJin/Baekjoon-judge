#include<cstdio>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;
int N, M, V;
vector<int> a[1001];
queue<int> q;
bool chk[1001];
void dfs(int node) {
	chk[node] = true;
	printf("%d ", node);
	for (int i = 0; i < a[node].size(); i++) {
		int next = a[node][i];
		if (chk[next] == false) dfs(next);
	}
}
void bfs(int node) {
	chk[node] = true;
	q.push(node);
	while (!q.empty()) {
		int x = q.front();
		q.pop();
		printf("%d ",x);
		for (int i = 0; i < a[x].size(); i++) {
			int y = a[x][i];
			if (chk[y] == false) chk[y] = true,	q.push(y);		
		}
	}
	
}
int main()
{
	scanf("%d %d %d",&N,&M,&V);
	for (int i = 0; i < M; i++) {
		int u, v;
		scanf("%d %d",&u,&v);
		a[u].push_back(v);
		a[v].push_back(u);
	}
	for (int i = 1; i <= N; i++) sort(a[i].begin(), a[i].end());
	dfs(V);
	puts("");
	for (int i = 1; i <= N; i++) chk[i] = false;
	bfs(V);
	return 0;
}