#include<iostream>
using namespace std;

int map[100][100];
long long d[100][100];
int n;

int main()
{
	ios::sync_with_stdio(false); cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			cin >> map[i][j];
		}
	}
	d[0][0] = 1;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			if (d[i][j] == 0) continue;
			if (i == n - 1 && j == n - 1) continue;
			int size = map[i][j];
			if (i + size < n) d[i + size][j] += d[i][j];
			if (j + size < n) d[i][j + size] += d[i][j];
		}
	}
	cout << d[n - 1][n - 1];
	return 0;
}