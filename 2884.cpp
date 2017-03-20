#include <iostream>
using namespace std;
const int day = 24 * 3600;
int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	int h, m, s = 0;
	cin >> h >> m;
	s = h * 3600 + m * 60;
	s -= 45 * 60;
	s = (s + day) % day;
	h = s / 3600;
	m = (s % 3600) / 60;
	cout << h << " " << m;
	return 0;
}