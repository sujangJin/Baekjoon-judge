#include<cstdio>
#include<cstring>
using namespace std;
char n[32];
int b, res, length;
int pow(int a, int b) {
	int res = 1;
	for (int i = 0; i < b; i++) {
		res *= a;
	}
	return res;
}
int main()
{
	scanf("%s %d",n,&b);
	length = strlen(n);
	for (int i = length-1; i >= 0; i--) {
		if (n[i] >= 'A' && n[i] <= 'Z') res += (n[i] - 'A' + 10) * pow(b, length - i - 1);
		else if (n[i] >= '1' && n[i] <= '9') res += (n[i] - '0') * pow(b, length - i - 1);
	}
	printf("%d",res);
	return 0;
}