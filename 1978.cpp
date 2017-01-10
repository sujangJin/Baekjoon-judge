#include<cstdio>
int n, num, cnt;
int main()
{
	scanf("%d",&n);
	while (n--) {
		bool flag = true;
		scanf("%d",&num);
		if (num < 2) flag = false;
		for (int i = 2; i*i <= num; i++) {
			if (num % i == 0) flag = false;
		}
		if(flag) cnt++;
	}
	printf("%d",cnt);
	return 0;
}