#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int d[1001][33][2];
int t, w;
vector<int> map;

int go(int time, int cnt, int curr) {
	int value = 0;
	if (time < 0 || cnt > w) return 0;
	if (time == 0) {
		if (map[time] == curr) return 1;
		else return 0;
	}
	else if (time == t) {
		return max(go(time - 1, cnt, curr), go(time - 1, cnt, !curr));
	}
	if (d[time][cnt][curr] != 0) return d[time][cnt][curr];

	if (map[time] == curr) value++;
	return d[time][cnt][curr] = max(go(time - 1, cnt, curr), go(time - 1, cnt + 1, !curr)) + value;
}

int main()
{
	ios::sync_with_stdio(false); cin.tie(0);
	cin >> t >> w;
	for (int i = 0; i < t; ++i) {
		int val; cin >> val;
		val--;
		map.push_back(val);
	}
	cout << go(t, 0, 0);
	return 0;
}