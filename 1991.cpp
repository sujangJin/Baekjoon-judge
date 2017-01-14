#include <cstdio>
int n, a[26][2];
void preorder(int start) {
	printf("%c", start + 'A');
	if (a[start][0] == -1 && a[start][1] == -1) return;
	if (a[start][0] != -1) preorder(a[start][0]);
	if (a[start][1] != -1) preorder(a[start][1]);
}
void inorder(int start) {
	if (a[start][0] != -1) inorder(a[start][0]);
	printf("%c", start + 'A');
	if (a[start][0] == -1 && a[start][1] == -1) return;
	if (a[start][1] != -1) inorder(a[start][1]);
}
void postorder(int start) {
	if (a[start][0] != -1) postorder(a[start][0]);
	if (a[start][1] != -1) postorder(a[start][1]);
	printf("%c", start + 'A');
	if (a[start][0] == -1 && a[start][1] == -1) return;
}
int main() {
	scanf("%d\n", &n);
	while (n--) {
		char root, L, R;
		scanf("%c %c %c\n", &root, &L, &R);

		if (L != '.')
			a[root - 'A'][0] = L - 'A';
		else
			a[root - 'A'][0] = -1;

		if (R != '.')
			a[root - 'A'][1] = R - 'A';
		else
			a[root - 'A'][1] = -1;
	}
	preorder(0);
	puts("");
	inorder(0);
	puts("");
	postorder(0);
	return 0;
}