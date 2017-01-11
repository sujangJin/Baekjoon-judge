#include<cstdio>
const int MAX = 1000000;
bool chk[MAX + 1];
int a, max;
int main()
{
	chk[0] = chk[1] = true;
	for (int i = 2; i <= MAX; i++) {
 		if (!chk[i]) for (int j = i + i; j <= MAX; j += i) chk[j] = true;
	}
	while (~scanf("%d",&a) && a != 0) {
		for (int i = 3; i <= a; i++) if (!chk[i] && !chk[a-i]) { max = i; break; }
		if (a>4 && a%2 == 0) printf("%d = %d + %d\n",a,max,a-max);
		else puts("Goldbach's conjecture is wrong.");
	}
	return 0;
}