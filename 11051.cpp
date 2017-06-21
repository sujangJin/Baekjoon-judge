#include<iostream>
using namespace std;
const int MOD = 10007;
int c[1001][1001];
int go(int n, int k) {
	if (c[n][k]) return c[n][k];

	if (n == 1 || k == 0 || n == k) return c[n][k] = 1;
	if (k == 1 || k == n - 1) return c[n][k] = n;
	return c[n][k] = (go(n - 1, k - 1) + go(n - 1, k)) % MOD;
}
int main()
{
	ios::sync_with_stdio(false); cin.tie(0);
	int N, K;
	cin >> N >> K;
	cout << go(N, K);
	return 0;
}