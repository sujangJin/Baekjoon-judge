#include<cstdio>
using namespace std;
int T, t, d[20] = { 1, 1, 2, };
int onetwothree(int n)
{
	if (n == 0 || n == 1 || n == 2) return d[n];
	else{
		d[n] = (onetwothree(n - 1) + onetwothree(n - 2) + onetwothree(n - 3));
		return d[n];
	}
}
int main()
{
	scanf("%d", &T);
	while (T--){
		scanf("%d", &t);
		if (t > 0 && t < 11)
			printf("%d\n", onetwothree(t));
	}
	return 0;
}