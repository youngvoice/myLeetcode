/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* nums, int numsSize, int target, int* returnSize){
		int i,j;
		int *indices;
		int diff;
		indices =(int *)malloc(2*sizeof(int));
		for (i = 0; i < (numsSize - 1); i++) {
				diff = target - nums[i];
				indices[0] = i;
				for (j = i+1; j < numsSize; j++) {
						indices[1] = j;
						if (nums[j] == diff) {
								*returnSize = 2;
								return indices;
						}
						else
								continue;
				}
				
		}
		*returnSize = 0;
		return NULL;
}

