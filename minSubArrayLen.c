int minSubArrayLen(int s, int* nums, int numsSize)
{
		int i,j,k,sum;
		int len = INT_MAX;
		sum = 0;
		for (i = 0; i < numsSize; i++)
				for (j = i; j < numsSize; j++) {
						sum = 0;
						for (k = i; k <= j; k++) {
								sum += nums[k];
								if (sum >= s) {
										if (j-i+1 < len)
												len = j-i+1;
								}
						}
				}
		return (len == INT_MAX) ? 0: len;

}

