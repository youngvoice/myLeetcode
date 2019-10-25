#include <stdio.h>
#include <stdlib.h>
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
#define RIGHT 0
#define DOWN 1
#define LEFT 2
#define UP 3
//int* spiralOrder(int** matrix, int matrixSize, int* matrixColSize, int* returnSize){
int* spiralOrder(int (*matrix)[4], int matrixSize, int* matrixColSize, int* returnSize){
		int i, j, r, c, k;
		int direction, directionChange;
		r = matrixSize;
		c = *matrixColSize;
		
		if (matrixSize == 0)
		{
				*returnSize = 0;
				return NULL;
		}

		*returnSize = r*c;
		// int *mask[];
		int **mask = (int **)malloc(r*sizeof(int *));
		int *nums = (int *)malloc(r*c*sizeof(int));

		for (i = 0; i < r; i++)
				mask[i] = (int *)malloc(c*sizeof(int));
		for (i = 0; i < r; i++)
				for (j = 0; j < c; j++)
						mask[i][j] = 0;

		i = 0;
		j = 0;
		k = 0;	

		nums[k++] = matrix[i][j];
		mask[i][j] = 1;
		direction = RIGHT;
		directionChange = 0;

		while (directionChange < 4)
		{

				if (direction == RIGHT) // -->
				{
						j++;
						if (j < c && mask[i][j] == 0)
						{
								nums[k++] = matrix[i][j];
								mask[i][j] = 1;
								directionChange = 0;
						}
						else
						{
								j--;
								direction = DOWN;
								directionChange++; 
						}
				}
				else if(direction == DOWN)
				{
						i++;
						if (i < r && mask[i][j] == 0)
						{
								nums[k++] = matrix[i][j];
								mask[i][j] = 1;
								directionChange = 0;
						}
						else
						{
								i--;
								direction = LEFT;
								directionChange++; 
						}

				}
				else if(direction == LEFT)
				{
						j--;
						if (j >= 0 && mask[i][j] == 0)
						{
								nums[k++] = matrix[i][j];
								mask[i][j] = 1;
								directionChange = 0;
						}
						else
						{
								j++;
								direction = UP;
								directionChange++; 
						}
				}
				else if(direction == UP)
				{
						i--;
						if (i >= 0 && mask[i][j] == 0)
						{
								nums[k++] = matrix[i][j];
								mask[i][j] = 1;
								directionChange = 0;
						}
						else
						{
								i++;
								direction = RIGHT;
								directionChange++; 
						}
				}
		}
	return nums;
}

int main()
{
		int matrix[3][4] = {
				{1,2,3,4},
				{5,6,7,8},
				{9,10,11,12}
		};
		
		int r = 3, c = 4;
		int *nums;
		int returnSize;

		nums = spiralOrder(matrix, r, &c, &returnSize);

}
