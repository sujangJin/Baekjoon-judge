#include<cstdio>
#include<iostream>
#include<vector>
#include<queue>
using namespace std;
int t,n,res;
vector<int> a[1001];
bool chk[1001];
void bfs(int v) {
	queue<int> q;
	chk[v] = true;
	q.push(v);
	while (!q.empty()) {
		int node = q.front();
		q.pop();
		for (int i = 0; i < a[node].size(); i++) {
			int next = a[node][i];
			if (chk[next] == false) chk[next] = true, q.push(next);
		}
	}
}
int main()
{
	ios::sync_with_stdio(false);
	scanf("%d",&t);
	while (t--) {
		int tmp;
		scanf("%d",&n);
		for (int i = 1; i <= n; i++) {
			cin >> tmp;
			a[i].push_back(tmp);
			a[tmp].push_back(i);
		}
		for (int i = 1; i <= n; i++) 
			if (chk[i] == false) bfs(i), res++;
		
		printf("%d\n",res);
		for (int i = 0; i <= n; i++) 
			a[i].clear(), chk[i] = false;
		res = 0;
	}
	return 0;
}