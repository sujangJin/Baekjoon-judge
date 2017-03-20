#include<iostream>
using namespace std;
int n, m;
char a[30][30];
bool left(int x, int y) {
	if (y - 1 >= 0 && (a[x][y - 1] == '+' || a[x][y - 1] == '-' || a[x][y - 1] == '1' || a[x][y - 1] == '2')) {
		return true;
	}
	else
		return false;
}

bool right(int x, int y) {
	if (y + 1 < m && (a[x][y + 1] == '+' || a[x][y + 1] == '-' || a[x][y + 1] == '3' || a[x][y + 1] == '4')) {
		return true;
	}
	else
		return false;
}

bool up(int x, int y) {
	if (x - 1 >= 0 && (a[x - 1][y] == '+' || a[x - 1][y] == '|' || a[x - 1][y] == '1' || a[x - 1][y] == '4')) {
		return true;
	}
	else
		return false;
}

bool down(int x, int y) {
	if (x + 1 < n && (a[x + 1][y] == '+' || a[x + 1][y] == '|' || a[x + 1][y] == '2' || a[x + 1][y] == '3')) {
		return true;
	}
	else
		return false;
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	cin >> n >> m;
	for (int i = 0; i < n; i++)	cin >> a[i];
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (a[i][j] != '.') continue;
			char ans = 0;
			if (left(i, j) && right(i, j) && up(i, j) && down(i, j)) {
				ans = '+';
			}
			else if (left(i, j) && right(i, j)) {
				ans = '-';
			}
			else if (up(i, j) && down(i, j)) {
				ans = '|';
			}
			else if (right(i, j) && down(i, j)) {
				ans = '1';
			}
			else if (right(i, j) && up(i, j)) {
				ans = '2';
			}
			else if (left(i, j) && up(i, j)) {
				ans = '3';
			}
			else if (left(i, j) && down(i, j)) {
				ans = '4';
			}

			if (ans != 0) {
				cout << i + 1 << " " << j + 1 << " " << ans;
				return 0;
			}
		}
	}
}