#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
int N, M,res;
vector<int> a[1001];
bool chk[1001];
void dfs(int node) {
	chk[node] = true;
	for (int i = 0; i < a[node].size(); i++) {
		int next = a[node][i];
		if (chk[next] == false) chk[next] = true, dfs(next);
	}
}
int main()
{
	scanf("%d %d",&N,&M);
	for (int i = 0; i < M; i++) {
		int u, v;
		scanf("%d %d",&u,&v);
		a[u].push_back(v);
		a[v].push_back(u);
	}
	for (int i = 1; i <= N; i++) sort(a[i].begin(), a[i].end());
	for (int i = 1;!a[i].empty(); i++) 
		if(chk[i] == false ) dfs(i), res++;
	printf("%d",res);
	return 0;
}