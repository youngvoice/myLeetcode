/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* numbers, int numbersSize, int target, int* returnSize)
{
		int *ret = (int *)malloc(2*sizeof(int));
		*returnSize = 2;
		int flag = 0;
		int i, j;
		for (i = 0; i < numbersSize; i++) {
				for (j = numbersSize - 1; i < j; j--) {
						if ((numbers[i] + numbers[j]) == target)
						{
								flag = 1;
								break;
						}
				}
				if (flag)
						break;
		}
		ret[0] = i + 1;
		ret[1] = j + 1;
		return ret;
}

