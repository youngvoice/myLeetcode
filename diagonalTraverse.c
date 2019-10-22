#include <stdio.h>
#include <stdlib.h>
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
//int* findDiagonalOrder(int **matrix, int matrixSize, int* matrixColSize, int* returnSize){
int* findDiagonalOrder(int matrix[][3], int matrixSize, int* matrixColSize, int* returnSize){
		int indexSum, i, j, k;
		int r = matrixSize;
		int c = *matrixColSize;
		int end = 0;
		int *output;
		if (matrixSize == 0)
		{
				*returnSize = 0;
				return NULL;
		}
		output = (int *)malloc(c*r*sizeof(int));
		*returnSize = c*r;
		i = 0;
		j = 0;
		k = 0;
		while (!end)
		{
				if ((i + j)%2 == 0)
				{
						output[k++] = matrix[i][j];
						i--;
						j++;
						// judge over index
						//if (i < 0 && j >= 0 && j < c)
						if (i < 0 && j < c)
								i++;
						else if(i < 0 && j >= c)
						{
								i = i + 2;
								j--;
						}
						else if(i >= 0 && j >= c)
						{
								i = i + 2;
								j--;
						}
						if (i == r && j == c - 1)
								end = 1;


				}
				else
				{
						output[k++] = matrix[i][j];
						i++;
						j--;
						if (i < r && j < 0)
								j++;
						else if (i >= r && j < 0)
						{
								i--;
								j = j + 2;
						}
						else if (i >= r && j >= 0)
						{
								i--;
								j = j + 2;

						}
						if (i == r -1 && j == c)
								end = 1;

				}
		}
		return output;
}

int main()
{
		int nums[3][3] = {
				{1, 2, 3},
				{4, 5, 6},
				{7, 8, 9}
		};
		int r = 3;
		int c = 3;
		int returnSize;
		int *order;
		order = findDiagonalOrder(nums, r, &c, &returnSize);
		for (int i = 0; i < r; i++)
		{
				for (int j = 0; j < c; j++)
				{
						printf("%d, ", *(order++));
				}
		}
		return 0;
}
