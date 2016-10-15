#include<cstdio>
#include<algorithm>

using namespace std;

int N;
int R[1001], G[1001], B[1001];
int x, y, z, A[1001][3];

int main()
{
	scanf("%d", &N);
	if (N < 1 || N > 1000) return 0;
	else {
		for (int i = 0; i < N; i++){
			scanf("%d %d %d", &R[i], &G[i], &B[i]);

		}

		A[0][0] = R[0];
		A[0][1] = G[0];
		A[0][2] = B[0];

		for (int i = 1; i < N; i++){

			A[i][0] = min(A[i - 1][1], A[i - 1][2]) + R[i];
			A[i][1] = min(A[i - 1][0], A[i - 1][2]) + G[i];
			A[i][2] = min(A[i - 1][0], A[i - 1][1]) + B[i];

		}

		printf("%d", min(min(A[N - 1][0], A[N - 1][1]), A[N - 1][2]));


	}
}