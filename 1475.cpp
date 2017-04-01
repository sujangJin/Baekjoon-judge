#include<iostream>
using namespace std;
int cnt[10];
int main()
{
	ios::sync_with_stdio(false); cin.tie(0);
	int n; cin >> n;
	while (n / 10) {
		cnt[n % 10]++;
		n /= 10;
	}
	cnt[n]++;
	
	cnt[6] += cnt[9];
	cnt[9] = 0;
	if (cnt[6] & 1) {
		cnt[6] /= 2;
		cnt[6]++;
	}
	else cnt[6] /= 2;

	int ans = 0;
	for (int i = 0; i < 10; i++) {
		if (ans < cnt[i]) ans = cnt[i];
	}
	cout << ans;
	return 0;
}