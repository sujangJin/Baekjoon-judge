#include <cstdio>
using namespace std;
int T;
char ps[50];
char * valid(char * s){
	int cnt = 0;
	for (int i = 0; s[i] != '\0'; i++){
		if (s[i] == '(')
			cnt++;
		else
			cnt--;

		if (cnt < 0)
			return "NO";
	}

	if (cnt == 0) return "YES";
	else	return "NO";
}
int main() {

	scanf("%d\n", &T);
	while (T--){

		scanf("%s", ps);
		printf("%s", valid(ps));
		if (T != 0) printf("\n");
	}
	return 0;
}