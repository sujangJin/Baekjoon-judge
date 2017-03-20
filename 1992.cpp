#include<cstdio>
int a[64][64];
int n;
void solve(int x_st, int x_end, int y_st, int y_end) {
	int standard = a[x_st][y_st];
	bool chk = true;
	for (int i = x_st; i < x_end && chk ; i++) {
		for (int j = y_st; j < y_end && chk; j++) {
			if (a[i][j] != standard) chk = false; 
		}
	}
	if (!chk) {
		printf("(");
		if (x_end -x_st == 2 && y_end - y_st == 2) {
			for (int i = x_st; i < x_end; i++) {
				for (int j = y_st; j < y_end; j++) {
					printf("%d",a[i][j]);
				}
			}
		}
		else {
			solve(x_st, (x_st + x_end) / 2, y_st, (y_st + y_end) / 2);
			solve(x_st, (x_st + x_end) / 2, (y_st + y_end) / 2, y_end);
			solve((x_st + x_end) / 2, x_end, y_st, (y_st + y_end) / 2);
			solve((x_st + x_end) / 2, x_end, (y_st + y_end) / 2, y_end);
		}
		printf(")");
	}
	else printf("%d", standard);
}
int main()
{
	scanf("%d",&n);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			scanf("%1d",&a[i][j]);
		}
	}
	solve(0, n, 0, n);
	return 0;
}