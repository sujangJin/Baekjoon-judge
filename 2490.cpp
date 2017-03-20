#include<cstdio>
using namespace std;
int main()
{
	for (int i = 0; i < 3; i++) {
		int cnt = 0;
		for (int j = 0, tmp; j < 4; j++) {
			scanf("%d", &tmp);
			if (tmp == 0) cnt++;
		}
		if (cnt == 4) puts("D");
		else if (cnt == 3) puts("C");
		else if (cnt == 2) puts("B");
		else if (cnt == 1) puts("A");
		else if (cnt == 0) puts("E");
	}
	return 0;
}