#include<iostream>
#include<algorithm>

using namespace std;
const int MAX = 1001;
int arr[MAX] = { 0, };
int F, S, L;

int main()
{
	int a, res = 0;

	for (int i = 1; i < 100; i++)
		arr[i] = 1;
	
	for (int i = 100; i < MAX; i++){
		F = i / 100;
		S = (i - F * 100) / 10;
		L = (i - F * 100) % 10;

		if (F + L == 2 * S)	arr[i] = 1;
	}


	cin >> a;
	if (a >= 1 && a <= 1000)
	{
		for (int i = 1; i <= a; i++){
			if (arr[i] == 1) res++;
		}

		cout << res;
	}
}