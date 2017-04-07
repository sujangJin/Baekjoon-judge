#include <iostream>
#include <vector>
#include <string>
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
	vector<int> where_is_from(n + 1, 0);
	q.push(st);
	where_is_from[st] = -1;
	while (!q.empty()) {
		int curr = q.front();
		q.pop();
		if (curr == ed) break;
		for (int i = 0; i < adj[curr].size(); i++) {
			int next = adj[curr][i];
			if (where_is_from[next] == 0) {
				where_is_from[next] = curr;
				q.push(next);
			}
		}
	}

	vector<int> ans;
	int start = ed;
	ans.push_back(ed);
	while (where_is_from[start] != -1 && where_is_from[start] != 0) {
		start = where_is_from[start];
		ans.push_back(start);
	}
	if (ans.back() != st) {
		cout << -1;
		return 0;
	}
	for (int i = ans.size() - 1; i >= 0; i--) {
		cout << ans[i] << " ";
	}

	return 0;
}