#include <stdio.h>
void mark (char (*grid)[3], int i, int gridSize, int j, int *gridColSize)
{

		if (i < 0 || i >= gridSize || j < 0 || j >= *gridColSize || grid[i][j] == '0')
				return;
		else
		{
				grid[i][j] = '0';
				mark(grid, i - 1, gridSize, j, gridColSize);
				mark(grid, i + 1, gridSize, j, gridColSize);
				mark(grid, i, gridSize, j - 1, gridColSize);
				mark(grid, i, gridSize, j + 1, gridColSize);
		}

}

int numIslands(char (*grid)[3], int gridSize, int *gridColSize)
{
		int i,j;
		int count = 0;
		if (gridSize == 0)
				return 0;
		for (i = 0; i < gridSize; i++)
				for (j = 0; j < *gridColSize; j++)
						if (grid[i][j] == '1') {
								count++;
								mark(grid, i, gridSize, j, gridColSize);
						}
		return count;
}


int main()
{
		char grid[3][3] = {
				{'1','0','0'},
				{'1','0','1'},
				{'1','0','0'}
		}
		int r = 3;
		int c = 3;
		printf("%d\n",numIslands(grid, r, &c));
}
