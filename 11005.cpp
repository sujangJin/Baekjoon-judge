#include<cstdio>
using namespace std;
int n,b,idx;
char res[32];
int main()
{
	scanf("%d %d",&n,&b);
	while (n) {
		int seg = n % b;
		if (seg < 10) {
			res[idx++] = seg + '0';
		}
		else {
			res[idx++] = (seg - 10) + 'A';
		}
		n /= b;
	}
	for(int i=idx-1;i>=0;i--) printf("%c",res[i]);
	return 0;
}