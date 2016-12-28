#include<cstdio>
using namespace std;
char str[100];
int cnt, idx;
int main()
{
	scanf("%s",str);
	for (int i = 0; str[i] != '\0'; i++) {
		if (str[i] == 'c') {
			if (str[i + 1] == '=' || str[i + 1] == '-') cnt++, i++;
		}
		else if (str[i] == 'd') {
			if (str[i + 1] == 'z' && str[i + 2] == '=') cnt += 2, i += 2;
			else if (str[i + 1] == '-') cnt++, i++;
		}
		else if (str[i] == 'l' || str[i] == 'n') {
			if (str[i + 1] == 'j') cnt++, i++;
		}
		else if (str[i] == 's' || str[i] == 'z') {
			if (str[i + 1] == '=') cnt++, i++;
		}
		idx = i+1;
	}
	printf("%d",idx-cnt);
	return 0;
}