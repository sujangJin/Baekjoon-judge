#include <cstdio>
using namespace std;
int res;
bool isNeg = false;
int main() {
	int tmp = 0;
	while (~scanf("%d", &tmp)) {
		if (isNeg && tmp >= 0) {
			res -= tmp;
		}
		else res += tmp;

		if (tmp < 0) isNeg = true;
	}
	printf("%d ", res);
	return 0;
}