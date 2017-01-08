#include<cstdio>
#include<iostream>
#include<string>
using namespace std;
string a, res;
int main()
{
	ios::sync_with_stdio(false);
	cin >> a;
	int i = a.length()-1, idx=0;
	while (i >= 0) {
		int seg = 0;
		if (i >= 2 && a[i - 2] != '\0') seg += (a[i - 2] - '0') * 4;
		if (i >= 1 && a[i - 1] != '\0') seg += (a[i - 1] - '0') * 2;
		seg += a[i] - '0';
		res += seg + '0';
		i -= 3;
	}
	for (int i = res.length() - 1; i >= 0; i--) printf("%d",res[i]-'0');
	return 0;
}