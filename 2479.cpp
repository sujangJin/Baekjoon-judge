#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <queue>
using namespace std;
int cmp(string a, string b) {
	int res = 0;
	for (int i = 0; i<a.length(); i++) {
		res += (a[i] ^ b[i]);
	}
	return res;
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	int n, k;
	cin >> n >> k;
	vector<string> a(n + 1);
	vector<vector<int>> adj(n + 1);
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	int st, ed;
	cin >> st >> ed;

	for (int i = 1; i <= n; i++) {
		for (int j = i + 1; j <= n; j++) {
			if (cmp(a[i], a[j]) == 1) {
				adj[i].push_back(j);
				adj[j].push_back(i);
			}
		}
	}

	queue<int> q;
	vector<int> dist(n + 1, -1);
	vector<int> parent(n + 1);
	
	q.push(st);
	dist[st] = 0;
	parent[st] = st;

	while (!q.empty()) {
		int curr = q.front();
		q.pop();

		if (curr == ed) break;

		for (int i = 0; i < adj[curr].size(); i++) {
			int next = adj[curr][i];

			if (dist[next] == -1) {
				q.push(next);
				dist[next] = dist[curr] + 1;
				parent[next] = curr;
			}
		}
	}
	
	vector<int> ans;
	int start = ed;
	ans.push_back(ed);

	while (parent[start] != start) {
		start = parent[start];
		ans.push_back(start);
	}
	
	if (ans.back() != st) {
		puts("-1");
		return 0;
	}
	for (int i = ans.size() - 1; i >= 0; i--) {
		cout << ans[i] << " ";
	}
	
	return 0;
}