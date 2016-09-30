#include<stdio.h>

int main()
{
	int input_sum = 0, input_cnt = 0;

	int res_start, i, tmp_sum;
	
	scanf("%d %d", &input_sum, &input_cnt);

	if (input_cnt < 2 || input_sum > 1000000000 || input_cnt > 100)
	{
		printf("-1 \n");
		return;
	}
	while (input_cnt <= 100){
		if (input_cnt % 2 == 0) // Even number, commit test
		{
			res_start = (input_sum / input_cnt) - (input_cnt / 2 - 1);
			tmp_sum = res_start * input_cnt + (input_cnt * (input_cnt - 1) / 2);
			if (res_start < 0 || tmp_sum != input_sum)	input_cnt++;
			else break;
		}
		else			// Odd number
		{
			res_start = (input_sum / input_cnt) - (input_cnt / 2);
			tmp_sum = res_start * input_cnt + (input_cnt * (input_cnt - 1) / 2);
			if (res_start < 0 || tmp_sum != input_sum)	input_cnt++;
			else break;
		}
	}
	
	if (input_cnt > 100)
	{
		printf("-1 \n");
	}
	else {
		for (i = 0; i < input_cnt; i++)
		{
			printf("%d ", res_start++);
		}
	}
	return 0;
}
