#include<iostream>
#include<string>
using namespace std;
string a, b;
int pow(int a, int b) {
	int res = 1;
	for (int i = 0; i < b; i++)
		res *= a;
	return res;
}
string rev(string str) {
	int res = 0;
	for (int i = 0; str[i] != '\0'; i++) {
		res += pow(10, i) * (str[i] - '0');
	}
	return to_string(res);
}
int main()
{
	ios::sync_with_stdio(false); cin.tie(0);
	cin >> a >> b;
	cout << rev(to_string(stoi(rev(a)) + stoi(rev(b))));
	return 0;
}