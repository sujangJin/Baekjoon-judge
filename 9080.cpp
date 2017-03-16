#include<cstdio>
#include<algorithm>
const int midnight = 24 * 60;
const int night = 22 * 60;
using namespace std;
int main()
{
	int t; scanf("%d", &t);
	while (t--) {
		int hh, mm, d;
		scanf("%d:%d %d", &hh, &mm, &d);
		int cost = 0;
		while (d > 0) {
			if (hh == 21 && mm != 0 && d >= 5 * 60 + mm) {
				d -= (60 - mm);
				mm = 0; hh++;
				cost++;
			}
			else if (((hh >= 22 && hh <= 24) || (hh >= 0 && hh <= 2) || (hh == 3 && mm == 0)) && d >= 5 * 60){
				if (hh >= 22) d -= 8 * 60 + (24 - hh) * 60;
				else d -= (8 - hh) * 60;
				if (mm != 0) d -= 60 - mm, cost++;
				hh = 8; mm = 0;
				cost += 5;
			}
			else if (d > 0 && d < 60) {
				mm += d;
				if (mm >= 60) mm %= 60, hh++;
				d = 0;
				cost++;
			}
			else {
				d -= 60;
				hh++;
				cost++;
			}
		}
		printf("%d\n", cost * 1000);
	}
	return 0;
}