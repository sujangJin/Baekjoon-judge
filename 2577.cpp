#include<cstdio>
#include<algorithm>

using namespace std;
int A, B, C;


int main()
{
	long long res;
	int arr[10] = { 0, };
	int share, remainder;
	scanf("%d", &A);
	scanf("%d", &B);
	scanf("%d", &C);

	res = A * B * C;

	while (res / 10 != 0)
	{
		share = res / 10;
		remainder = res % 10;

		arr[remainder] += 1;
		res = share;
	}
	
	arr[res] += 1;

	for (int i = 0; i < 10; i++){
		printf("%d\n",arr[i]);
	}
	
	return 0;
}