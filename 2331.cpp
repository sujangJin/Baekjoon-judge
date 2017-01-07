#include<cstdio>
using namespace std;
int a, p;
int chk[300001];
int main()
{
	int idx = 0;
	scanf("%d %d",&a,&p);
	while (!chk[a]) {
		chk[a] = idx;
		int res = 0;
		while (a > 0) {
			int num = a % 10, tmp=1;
			for (int i = 0; i < p; i++) tmp *= num;
			res += tmp;
			a /= 10;
		}
		idx++, a=res;
	}
	printf("%d",chk[a]);
	return 0;
}