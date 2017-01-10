#include<iostream>
#include<cstdio>
#include<stack>
#include<string>
using namespace std;
string str;
stack<int> st;
int main()
{
	ios::sync_with_stdio(false); cin.tie(0);
	cin >> str;
	int i = 0;
	bool first = true;
	while (str[i] != '\0') {
		int tmp = str[i] - '0', a;
		for (int i = 4; i >= 1; i /= 2) {
			a = tmp / i;
			tmp %= i;
			if (first && a == 0) continue; 
			else printf("%d",a);
			first = false;
		}
		i++;
	}
	if (str.size() == 1 && str[0] == '0') printf("0");
	return 0;
}