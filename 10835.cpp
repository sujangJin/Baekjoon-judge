#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
int d[2001][2001];
int lcard[2001];
int rcard[2001];
int n;
int go(int lidx, int ridx) 
{
	if (ridx == n) return 0;
	else if (lidx == n) return go(lidx, ridx + 1);

	int& ret = d[lidx][ridx];
	if (ret != -1) return ret;

	if (lcard[lidx] > rcard[ridx]) {
		return ret = max(ret, rcard[ridx] + go(lidx, ridx + 1));
	}
	else {
		return ret = max(go(lidx + 1, ridx), go(lidx + 1, ridx + 1));
	}
}
int main()
{
	memset(d, -1, sizeof(d));
	ios::sync_with_stdio(false);
	cin >> n;
	for (int i = 0; i < n; ++i) cin >> lcard[i];
	for (int i = 0; i < n; ++i) cin >> rcard[i];
	cout << go(0, 0);
	return 0;
}