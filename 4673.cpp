#include<iostream>
#include<algorithm>
#include<cmath>

using namespace std;
const int MAX = 10001;
int Num_arr[MAX] = { 0, };
void self_num(int num, int cnt);


int main()
{
	for (int i = 1; i < MAX; i++)
		self_num(i, 10000);
	for (int i = 1; i < MAX; i++){
		if (Num_arr[i] == 0) cout << i << "\n";
	}
	return 0;
}

void self_num(int num, int cnt)
{
	int res = num;
	while ((num / 10) != 0)
	{
		res += (num % 10);
		num = (num / 10);
	}
	res += num;		//가장 높은 자리의 숫자

	Num_arr[res] = 1;
	if (res <= cnt)	self_num(res, cnt);
}
