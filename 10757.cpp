#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
string a, b, res;
int main()
{
	ios::sync_with_stdio(false); cin.tie(0);
	cin >> a >> b;
	int max_loop = max(a.length(), b.length());
	
	int ai = a.length() - 1;
	int bi = b.length() - 1;
	bool carry = false;
	for (int i = 0; i < max_loop; i++, ai--, bi--) {
		int digit = 0;
		if (ai >= 0) digit += (a[ai] - '0');
		if (bi >= 0) digit += (b[bi] - '0');
		if (carry) {
			digit++;
			carry = false;
		}
		if (digit >= 10) {
			digit -= 10;
			carry = true;
		}
		res = to_string(digit) + res;
	}
	if (carry) res = '1' + res;
	cout << res;
	return 0;
}