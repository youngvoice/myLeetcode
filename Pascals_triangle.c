/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* getRow(int rowIndex, int* returnSize)
{
		int *array_pre, *array_cur;
		array_pre = (int *)malloc(sizeof(int));
		array_pre[0] = 1;
		int i, j;
		for (i = 1; i <= rowIndex; i++) {
				array_cur = (int *)malloc((i+1)*sizeof(int));
				array_cur[0] = 1;
				array_cur[i] = 1;
				for (j = 1; j < i; j++)
						array_cur[j] = array_pre[j-1] + array_pre[j];
				free(array_pre);
				array_pre = array_cur;

		}
		*returnSize = rowIndex + 1;
		return array_pre;
}

