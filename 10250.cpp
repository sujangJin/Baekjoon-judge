#include<iostream>
using namespace std;
int main()
{
	ios::sync_with_stdio(false);
	int tc; cin >> tc;
	while (tc--) {
		int floor, width, person;
		cin >> floor >> width >> person;
		if (person % floor == 0) {
			int ans34 = person / floor;
			if(ans34 < 10)
				cout << floor << "0" << ans34 << '\n';
			else
				cout << floor << ans34 << '\n';
		}
		else {
			int ans12 = person % floor;
			int ans34 = (person / floor) + 1;
			if (ans34 < 10)
				cout << ans12 << "0" << ans34 << '\n';
			else
				cout << ans12 << ans34 << '\n';
		}
	}
	return 0;
}