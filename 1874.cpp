#include <cstdio>
#include <stack>
using namespace std;
stack<int> st;
char res[200001];
int n, a, curr = 1, res_idx;
int main() {
	scanf("%d", &n);
	int t = n;
	while (t--) {
		scanf("%d", &a);
		if (a != 0 && a <= n) {
			if (curr <= a) {
				for (int i = curr; i <= a; i++) {
					st.push(i);
					res[res_idx++] = '+';
				}
				curr = a + 1;
				st.pop();
				res[res_idx++] = '-';
			}
			else {
				if (!st.empty() && st.top() == a) {
					st.pop();
					res[res_idx++] = '-';
				}
				else break;
			}
		}
		else break;
	}
	if (st.empty() && curr == n + 1) for (int i = 0; res[i] != '\0'; i++) printf("%c\n", res[i]);
	else printf("NO");
	return 0;
}