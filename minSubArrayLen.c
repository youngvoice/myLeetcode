int minSubArrayLen(int s, int* nums, int numsSize)
{
		int i,j,k,sum;
		int len = INT_MAX;

		int left = 0;
		sum = 0;
		for (i = 0; i < numsSize; i++) {
				sum += nums[i];
				while (sum >= s) {
						if (i + 1 - left < len)
								len = i + 1 - left;
						sum -= nums[left];
						left++; //**** if after left++, still have sum >= s, then the len is recalculating.
						//sum -= nums[left++];
				}
		}
		return (len == INT_MAX) ? 0: len;

}

