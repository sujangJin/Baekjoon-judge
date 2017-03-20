#include <cstdio>
using namespace std;
int a[10], tmp;
int main() {
	while (~scanf("%1d", &tmp)) a[tmp]++;
	for (int i = 9; i >= 0; i--) {
		if (a[i] != 0) printf("%d", i);
		a[i]--;
		if (a[i] >= 1) i++;
	}
	return 0;
}