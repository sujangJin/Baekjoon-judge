#include<cstdio>
using namespace std;
int N;
int main()
{
	scanf("%d", &N);
	for (int i = 1; i <= N; i++){
		for (int k = 1; k <= i; k++) printf("*");
		for (int j = 0; j<2 * (N - i); j++) printf(" ");
		for (int k = 1; k <= i; k++) printf("*");
		printf("\n");
	}
	for (int i = N - 1; i > 0; i--){
		for (int k = 1; k <= i; k++) printf("*");
		for (int j = 0; j<2 * (N - i); j++) printf(" ");
		for (int k = 1; k <= i; k++) printf("*");
		printf("\n");
	}
	return 0;
}