#include<iostream>
#define ll long long
using namespace std;
int a[10000];
int p, n;
int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	cin >> p >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	if (p <= n) {
		cout << p;
		return 0;
	}
	ll left = 0;
	ll right = 2 * 1e9*1e6;
	while (left <= right) {
		ll mid = (left + right) / 2;
		ll begin, end;
		begin = end = 0;
		end = n;
		for (int i = 0; i < n; i++) {
			end += mid / a[i];
		}
		begin = end;
		for (int i = 0; i<n; i++) {
			if (mid%a[i] == 0) {
				begin--;
			}
		}
		begin++;
		if (p < begin) {
			right = mid - 1;
		}
		else if (p > end) {
			left = mid + 1;
		}
		else {
			for (int i = 0; i<n; i++) {
				if (mid%a[i] == 0) {
					if (p == begin) {
						cout << i + 1;
						return 0;
					}
					begin++;
				}
			}
		}
	}
	return 0;
}