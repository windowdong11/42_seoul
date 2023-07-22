#include <stdio.h>

int ps_pow3(int n)
{
	static int results[20] = {1, };
	if (results[n] == 0)
		results[n] = 3 * ps_pow3(n - 1);
	return (results[n]);
}

int ps_nearpow3(int n)
{
	int i;
	int pow3;

	if (n <= 3)
		return 1;
	i = 0;
	while (i < 20)
	{
		if (ps_pow3(i) == n)
			return (ps_pow3(i - 1));
		if (n / 2 < ps_pow3(i) && n / 3 < ps_pow3(i))
			return (ps_pow3(i - 1));
		i++;
	}
	return -1;
}

void mock_merge_sort(int n)
{
	printf("merge_sort(%d)\n", n);
	if (n <= 3)
		return ;
	int divide = ps_nearpow3(n);
	int nums[] = {divide, divide, n - divide * 2};
	mock_merge_sort(nums[0]);
	mock_merge_sort(nums[1]);
	mock_merge_sort(nums[2]);
}

int main (){
	// mock_merge_sort(100);
	for (int i = 1; i < 100; i++)
		printf("nearpow3(%d) => %d\n", i, ps_nearpow3(i));
	return 0;
}