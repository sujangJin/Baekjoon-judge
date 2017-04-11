#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
int d[1001][1001];

int main()
{
	ios::sync_with_stdio(false); cin.tie(0);
	string a, b, res;
	cin >> a >> b;
	for (int i = 1; i <= a.size(); i++) {
		for (int j = 1; j <= b.size(); j++) {
			if (a[i - 1] == b[j - 1]) {
				d[i][j] = d[i - 1][j - 1] + 1;
			}
			else {
				d[i][j] = max(d[i - 1][j], d[i][j - 1]);
			}
		}
	}

	int i = a.size();
	int j = b.size();
	while (i >= 1 && j >= 1) {
		if (a[i - 1] == b[j - 1])
		{
			res = a[i - 1] + res;
			i--; j--;
		}
		else {
			if (d[i][j] == d[i - 1][j])
				i--;
			else if (d[i][j] == d[i][j - 1])
				j--;
		}
	}

	cout << d[a.size()][b.size()] << '\n' << res;
	return 0;
}