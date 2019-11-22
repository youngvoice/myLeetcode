int minSubArrayLen(int s, int* nums, int numsSize)
{
		int step, i, j;
		int sum;
		int flag = 0;
		int ret = 0;
		for (step = 0; step < numsSize; step++) {
				for (i = 0; i < numsSize - step; i++) {
						sum = 0;
						for (j = i; j < i + step + 1; j++)
								sum += nums[j];
						if (sum >= s) {
								flag = 1;
								break;
						}
				}
				if (flag) {
						ret = step + 1;
						return ret;
				}



		}
		return ret;
}
