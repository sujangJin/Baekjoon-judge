#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
int d[101][101][101];
int main()
{
	string a, b, c;
	cin >> a >> b >> c;
	for (int i = 1; i <= a.size(); i++) {
		for (int j = 1; j <= b.size(); j++) {
			for (int k = 1; k <= c.size(); k++) {
				if (a[i - 1] == b[j - 1] && b[j - 1] == c[k - 1]) {
					d[i][j][k] = d[i - 1][j - 1][k - 1] + 1;
				}
				else {
					int tmp = d[i][j - 1][k - 1];
					tmp = max({ tmp, d[i - 1][j][k - 1], d[i - 1][j - 1][k] });
					tmp = max({ tmp, d[i][j][k - 1], d[i][j - 1][k], d[i - 1][j][k] });
					d[i][j][k] = tmp;
				}
			}
		}
	}
	cout << d[a.size()][b.size()][c.size()];
	return 0;
}