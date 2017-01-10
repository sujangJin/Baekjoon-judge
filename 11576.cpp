#include<cstdio>
#include<queue>
#include<stack>
using namespace std;
stack<int> st, stDec;
int a, b, m, dec;
int pow(int a, int b)
{
	int res = 1;
	for (int i = 0; i < b; i++)
		res *= a;
	return res;
}
int main()
{
	scanf("%d%d",&a,&b);
	scanf("%d",&m);
	for (int i = 0, tmp; i < m; i++) {
		scanf("%d",&tmp);
		stDec.push(tmp);
	}
	int idx = 0;
	while (stDec.size()) { dec += stDec.top() * pow(a, idx++); stDec.pop(); }
	while (dec >= b) {
		st.push(dec % b);
		dec /= b;
	}
	st.push(dec);
	while (st.size()) { printf("%d ", st.top()); st.pop(); }
	return 0;
}