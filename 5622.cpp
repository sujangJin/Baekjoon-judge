#include<cstdio>
using namespace std;
int alpha[26], res;
char tel[15];
int main()
{
	int time = 3;
	for (int i = 0; i < 15; i++) {
		if (i % 3 == 0 && i != 0) time++;
		alpha[i] = time;
	}
	time++;
	for (int i = 0; i < 11; i++) {
		if (i % 4 == 0 && i != 0) time++;
		alpha[15 + i] = time;
	}
	alpha[(int)('W' - 'A')] = time;

	scanf("%s",tel);
	for (int i = 0; tel[i] != '\0'; i++) {
		res += alpha[(int)(tel[i] - 'A')];
	}
	printf("%d",res);
	return 0;
}