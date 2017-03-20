#include<cstdio>
#include<algorithm>
using namespace std;
int main()
{
	int h = 2000, c = h;
	for (int i = 0,tmp; i < 3; i++) {
		scanf("%d", &tmp);
		h = min(h, tmp);
	}
	for (int i = 0, tmp; i < 2; i++) {
		scanf("%d", &tmp);
		c = min(c, tmp);
	}
	printf("%d", h + c - 50);
	return 0;
}