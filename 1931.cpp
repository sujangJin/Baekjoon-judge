#include<iostream>
#include<algorithm>
using namespace std;
int n, curr, res;
const int MAX = 1e5;
struct conf{
	long start, end;
};
bool cmp(const conf a, const conf b) {
	if (a.end == b.end) {
		return a.start < b.start;
	}
	else return a.end < b.end;
}
int main()
{
	conf a[MAX];
	ios::sync_with_stdio(false); cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i].start >> a[i].end;
	}
	sort(a, a + n, cmp);
	for (int i = 0; i < n; i++) {
		if (curr <= a[i].start) {
			curr = a[i].end;
			res++;
		}
	}
	printf("%d",res);
	return 0;
}