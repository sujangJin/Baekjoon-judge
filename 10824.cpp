#include<cstdio>
#include<iostream>
#include<string>
using namespace std;
string a,b,c,d;
long long n1, n2;
int main()
{
	cin >> a >> b >> c >> d;
	a.append(b);
	c.append(d);
	n1 = stoll(a);
	n2 = stoll(c);
	printf("%lld",n1+n2);
	return 0;
}