#include <stdio.h>
#include <algorithm>
using namespace std;
int main(){
	int N, cnt = 0, input[100000] = { 0 }, temp, idx, i;
	scanf("%d", &N);
	for (i = 0; i<N; ++i){
		scanf("%d", &temp);
		idx = lower_bound(input, input + cnt, temp) - input;
		input[idx] = temp;
		if (idx == cnt) ++cnt;
	}
	printf("%d", N - cnt);
	return 0;
}