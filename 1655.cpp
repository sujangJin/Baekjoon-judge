#include<set>
#include<iostream>
using namespace std;
int n;
multiset<int> s;
int main()
{
	ios::sync_with_stdio(false); cin.tie(0);
	cin >> n;
	int tmp;
	cin >> tmp;
	cout << tmp << '\n';
	s.insert(tmp);
	multiset<int>::iterator it = s.find(tmp);
	for (int i = 2; i <= n; i++) {
		cin >> tmp;
		s.insert(tmp);
		if (tmp <= *it) {
			if (i % 2 == 0) {
				it--;
			}
		}
		else {
			if (i % 2 == 1) {
				it++;
			}
		}
		cout << *it << "\n";
	}
	return 0;
}