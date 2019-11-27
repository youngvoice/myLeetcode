int removeDuplicates(int* nums, int numsSize)
{
		int pre = nums[0];
		int k, i;
		if (numsSize == 0)
				return 0;
		for (k = 0, i = 0; k < numsSize; k++) {
				if (nums[k] != pre) {
						nums[++i] = nums[k];
				}
				pre = nums[k];

		}
		return i+1;
}
