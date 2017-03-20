#include<cstdio>
const int MAX = 1e5;
int n;
int in[MAX], post[MAX];
int location[MAX+1];
void solve(int in_st, int in_end, int ps_st, int ps_end) {
	if(in_st > in_end || ps_st > ps_end) return;
	int root = post[ps_end];
	printf("%d ",root);
	int p = location[root];
	int left = p-in_st;
	solve(in_st, p-1, ps_st, ps_st+left-1);
	solve(p+1, in_end, ps_st+left, ps_end-1);
}
int main()
{
	scanf("%d",&n);
	for (int i = 0; i < n; i++) scanf("%d",in+i);
	for (int i = 0; i < n; i++) scanf("%d",post+i);
	for (int i = 0; i < n; i++) location[in[i]] = i;
	solve(0, n-1, 0, n-1);
	return 0;
}