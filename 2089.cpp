#include<cstdio>
#include<stack>
using namespace std;
int a;
stack<int> st;
int main()
{
	scanf("%d",&a);
	while (1) {
		if (a == 0) break;
		else if (a == 1) { st.push(1); break; }
		else if (a == -1) {	st.push(1); st.push(1); break; }
		else {
			if (a > 0) {
				if (a % 2 == 0) st.push(0);
				else {
					st.push(1);
					a--;
				}
			}
			else {
				if (a % 2 == 0) st.push(0);
				else {
					st.push(1);
					a--;
				}
			}
			a /= -2;
		}
	}
	if (st.empty()) printf("0");
	else for (; st.size();) { printf("%d", st.top()); st.pop(); }
	return 0;
}