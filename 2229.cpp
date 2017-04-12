#include<iostream>
#include<algorithm>
using namespace std;
int score[1001], d[1001];
int main()
{
	ios::sync_with_stdio(false); cin.tie(0);
	int n; cin >> n;
	for (int i = 1; i <= n; i++) cin >> score[i];
	for (int i = 1; i <= n; i++) {
		int tmpMax = score[i], tmpMin = score[i];
		for (int j = i - 1; j >= 0; j--) {
			d[i] = max(d[i], d[j] + tmpMax - tmpMin);
			tmpMax = max(tmpMax, score[j]);
			tmpMin = min(tmpMin, score[j]);
		}
	}
	cout << d[n];

	return 0;
}
