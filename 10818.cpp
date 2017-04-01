#include<iostream>
using namespace std;
int MAX, MIN;
int main()
{
	ios::sync_with_stdio(false); cin.tie(0);
	int n; cin >> n;
	for (int i = 0, tmp; i < n; i++) 
	{
		cin >> tmp;
		if (i == 0) 
		{
			MAX = tmp;
			MIN = tmp;
		}
		else 
		{
			if (MAX < tmp) MAX = tmp;
			if (MIN > tmp) MIN = tmp;
		}
	}
	cout << MIN << " " << MAX;
	return 0;
}