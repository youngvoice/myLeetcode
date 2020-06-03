/*
void swap(int i, int j, int *nums);
void moveZeroes(int* nums, int numsSize)
{
		int i,j,k,t;
		for (i = numsSize - 1; i >= 0; i--) {
				if (nums[i] != 0) {
						k = i;
						break;
				}
		}
		for (i = k - 1; i >= 0; i--) {
				if (nums[i] == 0) {
						j = i;
						for (t = 0; t < k - j; t++)
								swap(j+t, j+1+t, nums);
						k--;
				}
		}
}

void swap(int i, int j, int *nums)
{
		int temp;
		temp = nums[i];
		nums[i] = nums[j];
		nums[j] = temp;
}
*/

/*
void moveZeroes(int* nums, int numsSize)
{
		int *retNums;
		int i, j;
		j = 0;
		retNums = (int *)malloc(numsSize*sizeof(int));
		for (i = 0; i < numsSize; i++)
				if (nums[i] != 0)
						retNums[j++] = nums[i];
		for (i = 0; i < numsSize; i++)
				if (nums[i] == 0)
						retNums[j++] = nums[i];
		for (i = 0; i < numsSize; i++)
				nums[i] = retNums[i];
}
*/

/*
void moveZeroes(int* nums, int numsSize)
{
		int i;
		int lastNonZero = 0;
		for (i = 0; i < numsSize; i++) {
				if (nums[i] != 0)
						nums[lastNonZero++] = nums[i];
		}
		for (i = lastNonZero; i < numsSize; i++) {
				nums[i] = 0;
		}
}

*/



void moveZeroes(int* nums, int numsSize){
	int i = 0, j = 0, tmp = 0, count = 0;
	for (j = 0; j < numsSize && count < numsSize; j++) {
        count++;
		if (nums[j] == 0) {
			i = j;
			for (; i+1 < numsSize; i++) {
				tmp = nums[i+1];
				nums[i+1] = nums[i];
				nums[i] = tmp;
			}
            j--;
            #for (i = 0; i < numsSize; i++) printf("%d ",nums[i]);
            #printf("\n");
                
			
		}
	}

}