#include<iostream>
#include<string>
#include<cstring>
using namespace std;
string bridge[2];
string step;
int d[2][101][20];
int go(int i, int j, int n) {
	
	if (j == bridge[0].length() && n != step.length())
		return 0;
	if (n == step.length()) 
		return 1;

	int& ret = d[i][j][n];
	if (ret != -1) return ret;

	ret = 0;
	for (int k = j; k < bridge[0].length(); ++k) {
		if (bridge[i][k] == step[n])
			ret += go(!i, k + 1, n + 1);
	}
	return ret;
}
int main()
{
	ios::sync_with_stdio(false); cin.tie(0);
	cin >> step >> bridge[0] >> bridge[1];
	memset(d, -1, sizeof(d));
	cout << go(0, 0, 0) + go(1, 0, 0);
	return 0;
}