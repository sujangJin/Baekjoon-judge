#include<iostream>
#include<cstdio>
using namespace std;
int a[10001],n;
int main()
{
	ios::sync_with_stdio(false); cin.tie(0);
	cin >> n;
	while (n--) {
		int tmp;
		cin >> tmp;
		a[tmp]++;
	}
	for (int i = 0; i < 10001; i++) {
		if(a[i] > 0) printf("%d\n",i), a[i]--, i--;
	}
	return 0;
}