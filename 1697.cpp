#include <cstdio>
#include <queue>
using namespace std;
const int MAX = 1e5;
int a[2 * MAX + 1];
bool chk[2 * MAX + 1];
int n, k;
int main()
{
	scanf("%d %d", &n, &k);
	queue<int> q;
	q.push(n);
	chk[n] = true;
	while (!q.empty()) {
		int curr = q.front();
		q.pop();

		if (n - 1 >= 0 && !chk[n-1]) { q.push(n - 1); chk[n - 1] = true; a[n - 1] = a[n] + 1; }
		if (n + 1 < 2 * MAX && !chk[n+1]) { q.push(n + 1); chk[n + 1] = true; a[n + 1] = a[n] + 1; }
		if (2 * n < 2 * MAX && !chk[2*n]) { q.push(2 * n); chk[2 * n] = true; a[2 * n] = a[n] + 1; }

	}
	printf("%d", a[k]);
	return 0;
}