#include<iostream>
#include<string>
using namespace std;
int main()
{
	ios::sync_with_stdio(false); cin.tie(0);
	string str; cin >> str;
	int n = str.length();
	int ans;

	for (ans = 0; ans < n; ++ans) {
		bool ok = true;
		for (int j = 0; j < n; ++j) {
			if (n - j - 1 + ans >= n) continue;
			if (str[j] != str[n - j - 1 + ans])
				ok = false;

			if (!ok) break;
		}
		if (ok) {
			cout << n + ans;
			return 0;
		}
	}

	return 0;
}