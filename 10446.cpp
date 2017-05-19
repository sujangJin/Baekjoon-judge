#include<iostream>
#include<vector>
#include<tuple>

using namespace std;

int main()
{
	ios::sync_with_stdio(false); cin.tie(0);
	int tc; cin >> tc;
	while (tc--) {
		int n, m;
		cin >> n >> m;
		vector<vector<int>> adj(n + 1);
		vector<vector<bool>> chk(n + 1, vector<bool>(n+1,false));
		
		for (int i = 0; i < m; i++) {
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		int limit = n + 1;
		vector<tuple<int,int,int>> res;
		int cnt = 0;
		bool ok = true;
		for (int i = 1; i <= n; i++) {
			for (int j = 0; j < adj[i].size(); j++) {
				int end = adj[i][j];
				if (chk[i][end] == false) {
					cnt++;
					if (cnt > limit) ok = false;
					chk[i][end] = true;
					chk[end][i] = true;

					if(cnt < limit)	res.push_back(make_tuple(i, end, cnt));
					else if(cnt == limit) res.push_back(make_tuple(i, end, 1));
				}
			}
		}

		if (ok) {
			for (int i = 0; i < res.size(); i++) {
				cout << get<0>(res[i]) << " " << get<1>(res[i]) << " " << get<2>(res[i]) << '\n';
			}
		}
		else {
			for (int i = 0; i < res.size(); i++) {
				cout << get<0>(res[i]) << " " << get<1>(res[i]) << " " << '0' << '\n';
			}
		}
		
	}
	return 0;
}