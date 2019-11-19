/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* numbers, int numbersSize, int target, int* returnSize)
{
		int *ret = (int *)malloc(2*sizeof(int));
		*returnSize = 2;
		int flag = 0;
		int i, j, sum;

		i = 0;
		j = numbersSize - 1;
		while (i < j) {
				sum = numbers[i] + numbers[j];
				if (sum == target) {
						flag = 1;
						break;
				}
				else {
						if (sum < target) 
								i++;
						else 
								j--;
				}

		}
		ret[0] = i + 1;
		ret[1] = j + 1;
		return ret;
}

