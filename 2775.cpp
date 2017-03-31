#include<iostream>
using namespace std;
int apt[15][16];
int main()
{
	ios::sync_with_stdio(false); cin.tie(0);
	for (int i = 1; i <= 15; i++) apt[0][i] = i;
	for (int i = 1; i <= 14; i++) {
		for (int j = 1; j <= 15; j++) {
			apt[i][j] = apt[i][j - 1] + apt[i - 1][j];
		}
	}
	int t; cin >> t;
	while (t--) {
		int floor, number;
		cin >> floor >> number;
		cout << apt[floor][number] << '\n';
	}
	return 0;
}