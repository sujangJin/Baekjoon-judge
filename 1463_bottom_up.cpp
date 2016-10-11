// this code was written by following URL
// URL : http://blog.naver.com/PostView.nhn?blogId=kks227&logNo=220777103650&parentCategoryNo=&categoryNo=299&viewDate=&isShowPopularPosts=false&from=postList
// 'BOTTOM-DOWN' method of Dynamic Programming 

#include<cstdio>
#include<algorithm>
using namespace std;

const int MAX = 1000001;

int main(){
	int N, dp[MAX];
	scanf("%d", &N);

	fill(dp, dp + MAX, 1000000000);
	dp[1] = 0; // base case
	for (int i = 1; i < N; i++){
		// use minimal function to choose 
		// whether to divide or not(just remove 1, -1)
		dp[i + 1] = min(dp[i + 1], dp[i] + 1);
		if (i * 2 < MAX) dp[i * 2] = min(dp[i * 2], dp[i] + 1);	
		if (i * 3 < MAX) dp[i * 3] = min(dp[i * 3], dp[i] + 1);
	}

	printf("%d", dp[N]);
	return 0;
}
