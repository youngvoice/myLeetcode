int removeElement(int* nums, int numsSize, int val)
{
		int i, k;

		for (i = 0, k = 0; i < numsSize; i++) {
				if (nums[i] != val) {
						nums[k] = nums[i];
						k++;
				}

		}
		return k;
}

