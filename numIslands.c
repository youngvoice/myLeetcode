void mark (char **grid, int i, int gridSize, int j, int *gridColSize)
{
		grid[i][j] = '0';
		if (i > 0) {
				if (grid[i-1][j] == '1')
						mark(grid, i-1, gridSize, j, *gridColSize);
		}
		if (i < (gridSize - 1)) {
				if (grid[i+1][j] == '1')
						mark(grid, i+1, gridSize, j, *gridColSize);
		}
		if (j > 0) {
				if (grid[i][j-1] == '1')
						mark(grid, i, gridSize, j-1, *gridColSize);
		}
		if (j < (*gridColSize - 1)) {
				if (grid[i][j+1] == '1')
						mark(grid, i, gridSize, j+1, *gridColSize);
		}
}

int numIslands(char **grid, int gridSize, int *gridColSize)
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



