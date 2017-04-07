#include<iostream>
#include<deque>
#include<map>
#define U 0
#define D 1
#define L 2
#define R 3
using namespace std;
int move_pos[4][2] = { {0,1}, {0,-1}, {-1,0}, {1,0} };
int n;
bool outofrange(int y, int x) {
	return (y > n || y < -n || x > n || x < -n);
}
int changeDirection(int curr, char arrow) {
	int res = 0;
	switch (curr) 
	{
	case U:
		if (arrow == 'L') res = L;
		else if (arrow == 'R') res = R;
		break;
	case D:
		if (arrow == 'L') res = R;
		else if (arrow == 'R') res = L;
		break;
	case L:
		if (arrow == 'L') res = D;
		else if (arrow == 'R') res = U;
		break;
	case R:
		if (arrow == 'L') res = U;
		else if (arrow == 'R') res = D;
		break;
	}
	return res;
}
bool twisted_inner(deque<pair<int,int>> &dq, int x, int y) {
	for (int i = 0; i < dq.size(); i++) {
		if (dq[i].first == x && dq[i].second == y) return true;
	}
	return false;
}
int main()
{
	ios::sync_with_stdio(false); cin.tie(0);
	cin >> n;
	int t; cin >> t;
	map<int, char> change;
	int time = 1;
	while (t--) {
		int after;
		char side;
		cin >> after >> side;
		time += after;
		change[time] = side;
	}
	
	deque<pair<int, int>> dq;
	dq.push_back(make_pair(0, 0));
	int elapsed_time = 0;
	int direction = R;
	while (1) {
		elapsed_time++;
		if (change[elapsed_time] == 'L' || change[elapsed_time] == 'R') {
			direction = changeDirection(direction, change[elapsed_time]);
		}
		int x = dq.front().first;
		int y = dq.front().second;
		int nx = x + move_pos[direction][0];
		int ny = y + move_pos[direction][1];
		if (twisted_inner(dq, nx, ny)) break;
		if (outofrange(nx, ny)) break;
		dq.push_front(make_pair(nx, ny));
	}
	cout << elapsed_time;

	return 0;
}