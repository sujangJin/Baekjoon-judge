#include<iostream>
#include<vector>
#include<string>
using namespace std;
string top = "  *  ";
string mid = " * * ";
string bot = "*****";
vector<string> arr;
int cnt;
int mod(int val) {
	int res = 3;
	for (int i = 1; i < val; ++i)
		res *= 2;
	return res;
}
void go(int num) {
	if (num == cnt + 1) return;
	if (arr.empty()) {
		arr.push_back(top);
		arr.push_back(mid);
		arr.push_back(bot);
		go(num + 1);
	}
	else {
		int size = arr.size();
		for (int i = 0; i < size; ++i) {
			string tmp = arr[i] + " " + arr[i];
			arr.push_back(tmp);
		}
		for (int i = 0; i < size; ++i) {
			for (int j = 0; j < mod(num); ++j) 	arr[i] = " " + arr[i];
			for (int j = 0; j < mod(num); ++j) 	arr[i] += " ";
		}
		go(num + 1);
	}
}
int main()
{
	ios::sync_with_stdio(false); cin.tie(0);
	int n; cin >> n;
	
	n /= 3;
	while (n != 1) {
		cnt++;
		n /= 2;
	}

	go(0);
	for (int i = 0; i < arr.size(); ++i) {
		cout << arr[i] << '\n';
	}
	return 0;
}