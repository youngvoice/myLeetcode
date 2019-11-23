void rotate(int* nums, int numsSize, int k)
{


		int i, j, temp, previous;
		for (j = 0; j < k; j++) {
				previous = nums[numsSize - 1];
				for (i = 0; i < numsSize; i++) {
						temp = nums[i];
						nums[i] = previous;
						previous = temp;

				}
		}

		/*
		int i, j, temp;
		for (j = 0; j < k; j++)
		for (i = numsSize - 1; i > 0; i--) {
				temp = nums[i];
				nums[i] = nums[i - 1];
				nums[i - 1] = temp;
		}
		*/

}

