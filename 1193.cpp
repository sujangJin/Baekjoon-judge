#include <cstdio>
using namespace std;
int x, i;
int main() {
	scanf("%d", &x);
	for (i = 1; i*(i + 1) / 2<x; i++);
	int remainder = x - (i - 1)*i / 2;
	if ((i - 1) % 2 == 1) printf("%d/%d", remainder, i + 1 - remainder);
	else printf("%d/%d", i + 1 - remainder, remainder);
	return 0;
}