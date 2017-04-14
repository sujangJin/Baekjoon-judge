#include<iostream>
#include<vector>
using namespace std;
int main()
{
	ios::sync_with_stdio(false); cin.tie(0);
	int n; cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; i++)
		cin >> a[i];
	int first, second;
	cin >> first >> second;
	
	long long res = 0;
	for (int i = 0; i < n; i++) {
		res++;
		a[i] -= first;
		if (a[i] > 0) {
			res += a[i] / second;
			if (a[i] % second > 0) res++;
		}
	}
	cout << res;
	return 0;
}