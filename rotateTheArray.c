void rotate(int* nums, int numsSize, int k)
{

		int i, j, temp;
		for (j = 0; j < k; j++)
		for (i = numsSize - 1; i > 0; i--) {
				temp = nums[i];
				nums[i] = nums[i - 1];
				nums[i - 1] = temp;
		}

}

