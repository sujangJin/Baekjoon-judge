#include<cstdio>
int a[20][20];
int d[21][20][20][20][20];
int main()
{
	int n, L;
	scanf("%d %d",&n,&L);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			scanf("%d", &a[i][j]);
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			d[1][i][j][i][j] = 1;
		}
	}

	for (int x1 = 0; x1 < n; x1++) {
		for (int y1 = 0; y1 < n; y1++) {

			for (int x2 = x1 - 1; x2 <= x1 + 1; x2++) {
				for (int y2 = y1 - 1; y2 <= y1 + 1; y2++) {

					if (x2 >= 0 && x2 < n && y2 >= 0 && y2 < n) {
						if (!(x1 == x2 && y1 == y2)) {
							if (a[x1][y1] == a[x2][y2]) {
								d[2][x1][y1][x2][y2] = 1;
							}
						}
					}

				}
			}

		}
	}

	for (int l = 3; l <= L; l++) {
		for (int x1 = 0; x1 < n; x1++) {
			for (int y1 = 0; y1 < n; y1++) {
				for (int x2 = 0; x2 < n; x2++) {
					for (int y2 = 0; y2 < n; y2++) {
						
						if (a[x1][y1] == a[x2][y2]) {
							for (int x3 = x1 - 1; x3 <= x1 + 1; x3++) {
								for (int y3 = y1 - 1; y3 <= y1 + 1; y3++) {
									
									for (int x4 = x2 - 1; x4 <= x2 + 1; x4++) {
										for (int y4 = y2 - 1; y4 <= y2 + 1; y4++) {
											if (x3 >= 0 && x3 < n && y3 >= 0 && y3 < n) {
												if (x4 >= 0 && x4 < n && y4 >= 0 && y4 < n) {
													if (!(x1 == x3 && y1 == y3) && !(x2 == x4 && y2 == y4)) {
														d[l][x1][y1][x2][y2] += d[l - 2][x3][y3][x4][y4];
													}
												}
											}
										}
									}

								}
							}
						}

					}
				}
			}
		}
	}

	int ans = 0;
	for (int x1 = 0; x1 < n; x1++) {
		for (int y1 = 0; y1 < n; y1++) {
			for (int x2 = 0; x2 < n; x2++) {
				for (int y2 = 0; y2 < n; y2++) {
					ans += d[L][x1][y1][x2][y2];
				}
			}
		}
	}
	printf("%d",ans);
	return 0;

}