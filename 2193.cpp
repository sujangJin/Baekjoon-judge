#include<cstdio>
#include<stdlib.h>
#include<algorithm>
using namespace std;
const int MAX = 91;

int main()
{
	// if array type is integer, the result is negative(garbage) when n is 90
	// so it must be a long long type
	long long int dp[MAX][2];
	long long int n = 0;
	
	scanf("%lld",&n);
	if (n <1 || n >90)
		return -1;

	//initializing array
	for (int i = 0; i < MAX; i++){
		for (int j = 0; j < 2; j++){
			dp[i][j] = 0;
		}
	}
	// set the base case
	dp[1][1] = 1; 
	
	// using bottom-up DP
	for (int i = 1; i < n; i++){
		dp[i + 1][0] = dp[i][0] + dp[i][1];
		dp[i + 1][1] = dp[i][0];
	}

	printf("%lld",dp[n][0]+dp[n][1]);
	return 0;
}