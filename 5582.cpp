#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
int d[4001][4001];
int res;
int main()
{
	ios::sync_with_stdio(false); cin.tie(0);
	string a, b;
	cin >> a >> b;

	for (int i = 0; i < a.length(); ++i) {
		for (int j = 0; j < b.length(); ++j) {
			if (a[i] == b[j]) {
				if (i == 0 || j == 0)
					d[i][j] = 1;
				else
					d[i][j] = d[i - 1][j - 1] + 1;
				res = max(res, d[i][j]);
			}
		}
	}
	cout << res;
	return 0;
}