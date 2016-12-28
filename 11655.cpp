#include<cstdio>
#include<iostream>
#include<string>
using namespace std;
string a;
int main()
{
	getline(cin, a);
	for (int i = 0; i < a.size(); i++) {
		int tmp=0;
		if (a[i] >= 'a' && a[i] <= 'z') {
			tmp = (a[i] - 'a' + 13) % 26;
			a[i] = tmp + 'a';
		}
		else if(a[i] >= 'A' && a[i] <= 'Z') {
			tmp = (a[i] - 'A' + 13) % 26;
			a[i] = tmp + 'A';
		}
		printf("%c",a[i]);
	}
	return 0;
}