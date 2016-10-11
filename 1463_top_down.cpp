// this code was written by following URL
// URL : http://blog.naver.com/PostView.nhn?blogId=kks227&logNo=220777103650&parentCategoryNo=&categoryNo=299&viewDate=&isShowPopularPosts=false&from=postList
// 'TOP-DOWN' method of Dynamic Programming 

#include<cstdio>
#include<algorithm>

using namespace std;
const int MAX = 1000001;

int dp[MAX];

int f(int n){
	if (n == 1) return 0;
	if (dp[n] != -1) return dp[n];

	int result = f(n - 1) + 1;
	if (n % 3 == 0) result = min(result, f(n / 3) + 1);
	if (n % 2 == 0) result = min(result, f(n / 2) + 1);
	dp[n] = result;
	return result;
}

int main(){
	int N;
	scanf("%d",&N);
	fill(dp, dp + MAX, -1);
	printf("%d\n", f(N));
}
