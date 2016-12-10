#include<cstdio>
using namespace std;
int T;
int main()
{
	scanf("%d", &T);
	if (T >= 1 && T <= 100){
		for (int i = 0; i<T; i++){
			for (int j = T - i-1; j > 0; j--) printf(" ");
			for (int k = 0; k<=i; k++) printf("*");
			printf("\n");
		}
		for (int i = 1; i<T; i++){
			for (int j = 0; j<i; j++) printf(" ");
			for (int k = T - i - 1; k >= 0; k--) printf("*");
			printf("\n");
		}
	}
	return 0;
}