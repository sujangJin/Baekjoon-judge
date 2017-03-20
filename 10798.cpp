#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
int main()
{
	ios::sync_with_stdio(false); cin.tie(0);
	string a, b, c, e, d;
	cin >> a >> b >> c >> d >> e;
	int len = max({ a.length(), b.length(), c.length(), d.length(), e.length() });
	for (int i = 0; i < len; i++) {
		if (a.length() > i) cout << a[i];
		if (b.length() > i) cout << b[i];
		if (c.length() > i) cout << c[i];
		if (d.length() > i) cout << d[i];
		if (e.length() > i) cout << e[i];
	}
	return 0;
}