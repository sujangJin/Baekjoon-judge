#include <cstdio>
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;
int N;
struct Student {
	int kor, eng, math;
	string name;
};
bool cmp(const Student &u, const Student &v) {
	if (u.kor > v.kor)
		return true;
	else if (u.kor == v.kor) {
		if (u.eng < v.eng)
			return true;
		else if (u.eng == v.eng) {
			if (u.math > v.math)
				return true;
			else if (u.math == v.math)
				return u.name < v.name;
		}
	}
	return false;
}
int main()
{
	ios::sync_with_stdio(false);
	cin >> N;
	vector<Student> a(N);
	for (int i = 0; i<N; i++) {
		cin >> a[i].name >> a[i].kor >> a[i].eng >> a[i].math;
	}
	sort(a.begin(), a.end(),cmp);
	for (int i = 0; i<N; i++) cout << a[i].name << '\n';
	return 0;
}
