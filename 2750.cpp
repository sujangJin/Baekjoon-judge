#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;
vector<int> arr;
const int MAX = 10000;

int main()
{
	int N, tmp, before = MAX;
	cin >> N;
	if (N >= 1 && N <= 1000){
		for (int i = 0; i < N; i++){
			cin >> tmp;
			if (abs(tmp) <= 1000 && before != tmp) arr.push_back(tmp);
			before = tmp;
		}
	}

	sort(arr.begin(), arr.end());

	for (int i = 0; i < arr.size(); i++){
		cout << arr.at(i) << "\n";
	}
	return 0;
}