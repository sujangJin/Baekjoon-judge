#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int N, S, L;
vector<int> arr;
int d[1001][100];
int go(int vol, int cnt) {
	if (cnt == N) return d[vol][cnt] = max(d[vol][cnt], vol);
	if (d[vol][cnt] != 0) return d[vol][cnt];

	int res = -1;
	if (vol - arr[cnt] >= 0) res = max(res, go(vol - arr[cnt], cnt + 1));
	if (vol + arr[cnt] <= L) res = max(res, go(vol + arr[cnt], cnt + 1));
	return d[vol][cnt] = res;
}
int main()
{
	ios::sync_with_stdio(false); cin.tie(0);
	cin >> N >> S >> L;
	for (int i = 0; i < N; ++i) {
		int val; cin >> val;
		arr.push_back(val);
	}
	cout << go(S, 0);
	return 0;
}