#include<iostream>
using namespace std;
int main()
{
	ios::sync_with_stdio(false); cin.tie(0);
	int n; cin >> n;
	int ball_location = 1;
	while (n--) {
		int x, y;
		cin >> x >> y;
		if (ball_location == x) ball_location = y;
		else if (ball_location == y) ball_location = x;
	}
	cout << ball_location;
	return 0;
}