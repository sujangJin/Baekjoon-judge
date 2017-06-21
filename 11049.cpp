#include<iostream>
#include<climits>
#include<vector>
#include<cstring>
#include<algorithm>
using namespace std;
int dp[501][501];
vector<pair<int, int>> v;
int solve(int p, int q)
{
	if (p == q) return 0;
	if (p + 1 == q)
		return v[p].first * v[p].second * v[q].second;

	int& ret = dp[p][q];
	if (ret != -1) return ret;
	ret = INT_MAX;
	for (int i = p; i < q; ++i)
		ret = min(ret, solve(p, i) + solve(i + 1, q) + v[p].first * v[i].second * v[q].second);

	return ret;
}
int main()
{
	ios::sync_with_stdio(false); cin.tie(0);
	int n; cin >> n;
	for (int i = 0; i < n; ++i) {
		int a, b; cin >> a >> b;
		v.push_back(make_pair(a, b));
	}
	memset(dp, -1, sizeof(dp));
	cout << solve(0, n - 1);
	return 0;
}
