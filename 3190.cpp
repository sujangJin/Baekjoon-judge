#include<iostream>
#include<deque>
#include<map>
using namespace std;
deque<pair<int, int>> snake;
int gmap[101][101], runtime;
int directionX[] = {0,-1,0,1};
int directionY[] = {-1,0,1,0};
bool bumped_inside(int x, int y) {
	bool ok = false;
	for (int i = 0; i < snake.size(); i++) {
		if (snake[i].first == x && snake[i].second == y) {
			ok = true;
			break;
		}
	}
	return ok;
}
int main()
{
	ios::sync_with_stdio(false); cin.tie(0);
	int n;  cin >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			gmap[i][j] = 1;
		}
	}
	int apple; cin >> apple;
	while (apple--) {
		int x, y;
		cin >> x >> y;
		gmap[x][y] = 2;
	}
	map<int, char> change;
	int l; cin >> l;
	while (l--) {
		char direction;
		int sec;
		cin >> sec >> direction;
		change[sec] = direction;
	}
	// -------input-----------------
	snake.push_back({ 1,1 });
	int current_direction = 2;
	while (1) {
		// change direction
		if (change[runtime] == 'L' || change[runtime] == 'D') {
			if (change[runtime] == 'L') {
				current_direction -= 1;
				current_direction += 4;
				current_direction %= 4;
			}
			else {
				current_direction++;
				current_direction += 4;
				current_direction %= 4;
			}
		}
		
		int x = snake.front().first;
		int y = snake.front().second;
		int nx = x + directionX[current_direction];
		int ny = y + directionY[current_direction];
		// exit condition
		if (nx == 0 || ny == 0 || nx > n || ny > n) break;
		if (bumped_inside(nx, ny)) break;
		// check, eat apple or not
		snake.push_front({ nx,ny });
		if (gmap[nx][ny] == 1) snake.pop_back();
		// if snake eats an apple, change the map
		if (gmap[nx][ny] == 2) gmap[nx][ny] = 1;

		runtime++;
	}
	cout << runtime+1;
	return 0;
}