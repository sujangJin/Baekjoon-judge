#include<cstdio>
#include<iostream>
#include<stdio.h>
using namespace std;
char a[101];
int res[4];
int main()
{
	while (cin.getline(a,101)) {
		for (int i = 0; a[i] != '\0'; i++) {
			if (a[i] >= '0' && a[i] <= '9') res[2]++;
			else if (a[i] == ' ') res[3]++;
			else if (a[i] >= 'A' && a[i] <= 'Z') res[1]++;
			else if (a[i] >= 'a' && a[i] <= 'z') res[0]++;
		}
		for (int i = 0; i < 4; i++) {
			printf("%d ", res[i]);
			res[i] = 0;
		}
		printf("\n");
		
	}
	return 0;
}