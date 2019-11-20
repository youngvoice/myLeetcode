int findMaxConsecutiveOnes(int* nums, int numsSize)
{
		int max_count = 0;
		int i, j;
		for (i = 0, j = -1; i < numsSize; i++) {
				if ((nums[i] != 1) || (i == (numsSize - 1))) {
						if (i == (numsSize - 1) && (nums[i] == 1))
								i++;
						if ((i - j - 1) > max_count) 
								max_count = i - j - 1;
						j = i;
				}

				

		}
		return max_count;
}
