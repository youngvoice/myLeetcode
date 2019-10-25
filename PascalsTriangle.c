#include <stdio.h>
#include <stdlib.h>
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** generate(int numRows, int* returnSize, int** returnColumnSizes){
		int **matrix;
		int lineSize, *line;
		int i, j, s;

		if (numRows == 0)
		{
				*returnSize = numRows;
				returnColumnSizes = NULL;
				return NULL;
		}

		*returnSize = numRows;
		*returnColumnSizes = (int *)malloc(numRows*sizeof(int));
		

		matrix = (int **)malloc(numRows*sizeof(int *));
		for (i = 0; i < numRows; i++)
		{
				s = i + 1;
				line = (int *)malloc(s*sizeof(int));
				if (s != 1)
				{
						line[0] = 1;

						for (j = 1; j < (s - 1); j++)
								line[j] = matrix[i-1][j - 1] + matrix[i-1][j];

						line[s - 1] = 1;

				}
				else
				{

						line[0] = 1;
				}


				(*returnColumnSizes)[i] = s;
				matrix[i] = line;
		}
		return matrix;
}
//int** generate(int numRows, int* returnSize, int** returnColumnSizes){
//
#define NUMS 5
int main()
{
		int returnSize;
		int *returnColumnSizes = (int *)malloc(NUMS*sizeof(int));
		int **matrix;
		matrix = generate(NUMS, &returnSize, &returnColumnSizes);

}
