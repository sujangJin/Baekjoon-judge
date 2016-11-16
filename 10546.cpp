#include<iostream>
#include<algorithm>
#include<vector>
#include<string>

using namespace std;

long long Number = 0;
vector<string> a1, a2;
bool res = false;
string tmp;

int main()
{
	cin >> Number;
	for (int i = 0; i < Number; i++)
	{
		cin >> tmp;
		if (tmp.size() >= 1 && tmp.size() <= 20)
			a1.push_back(tmp);
	}

	for (int i = 0; i < Number - 1; i++)
	{
		cin >> tmp;
		if (tmp.size() >= 1 && tmp.size() <= 20)
			a2.push_back(tmp);
	}
	
	sort(a1.begin(), a1.end());
	sort(a2.begin(), a2.end());

	for (int i = 0; i < Number-1; i++)
	{
		if (a1.at(i) != a2.at(i))
		{
			cout << a1.at(i);
			res = true;
			break;
		}
	}

	if (res == false)
		cout << a1.at(Number-1);
	return 0;
}