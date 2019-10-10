int mark (char **grid, int i, int gridSize, int j, int *gridColSize)
{
		if ( i == 0 && j == 0) {
				if (grid[i+1][j] == '1') {
						grid[i+1][j] = '2';
						mark(grid, i+1, gridSize, j, gridColSize);
				}
				if (grid[i][j+1] == '1') {
						grid[i][j+1] = '2';
						mark(grid, i, gridSize, j+1, gridColSize);
				}
		}
		else if ( i == 0 && j == (*gridColSize - 1)) {
				if (grid[i+1][j] == '1') {
						grid[i+1][j] = '2';
						mark(grid, i+1, gridSize, j, gridColSize);
				}
				if (grid[i][j - 1] == '1') {
						grid[i][j - 1] = '2';
						mark(grid, i, gridSize, j-1, gridColSize);
				}

		}

		else if ( i == (gridSize - 1) && j == 0) {
				if (grid[i-1][j] == '1') {
						grid[i-1][j] = '2';
						mark(grid, i-1, gridSize, j, gridColSize);
				}
				if (grid[i][j + 1] == '1') {
						grid[i][j + 1] = '2';
						mark(grid, i, gridSize, j+1, gridColSize);
				}
		}
		else if ( i == (gridSize -1 ) && j == (*gridColSize - 1)) {
				if (grid[i][j-1] == '1') {
						grid[i][j-1] = '2';
						mark(grid, i, gridSize, j-1, gridColSize);
				}
				if (grid[i-1][j] == '1') {
						grid[i-1][j] = '2';
						mark(grid, i-1, gridSize, j, gridColSize);
				}
		}
		else if (i == 0) {
				if (grid[i+1][j] == '1') {
						grid[i+1][j] = '2';
						mark(grid, i+1, gridSize, j, gridColSize);
				}
				if (grid[i][j+1] == '1') {
						grid[i][j+1] = '2';
						mark(grid, i, gridSize, j+1, gridColSize);
				}
				if (grid[i][j-1] == '1') {
						grid[i][j-1] = '2';
						mark(grid, i, gridSize, j-1, gridColSize);
				}

		}
		else if (i == gridSize -1) {
				if (grid[i][j+1] == '1') {
						grid[i][j+1] = '2';
						mark(grid, i, gridSize, j+1, gridColSize);
				}
				if (grid[i][j-1] == '1') {
						grid[i][j-1] = '2';
						mark(grid, i, gridSize, j-1, gridColSize);
				}
				if (grid[i-1][j] == '1') {
						grid[i-1][j] = '2';
						mark(grid, i-1, gridSize, j, gridColSize);
				}
		}
		else if (j == 0) {
				if (grid[i+1][j] == '1') {
						grid[i+1][j] = '2';
						mark(grid, i+1, gridSize, j, gridColSize);
				}
				if (grid[i][j+1] == '1') {
						grid[i][j+1] = '2';
						mark(grid, i, gridSize, j+1, gridColSize);
				}
				if (grid[i-1][j] == '1') {
						grid[i-1][j] = '2';
						mark(grid, i-1, gridSize, j, gridColSize);
				}
		}
		else if (j == *gridColSize - 1) {
				if (grid[i+1][j] == '1') {
						grid[i+1][j] = '2';
						mark(grid, i+1, gridSize, j, gridColSize);
				}
				if (grid[i][j-1] == '1') {
						grid[i][j-1] = '2';
						mark(grid, i, gridSize, j-1, gridColSize);
				}
				if (grid[i-1][j] == '1') {
						grid[i-1][j] = '2';
						mark(grid, i-1, gridSize, j, gridColSize);
				}
		}
		else
		{
				if (grid[i+1][j] == '1') {
						grid[i+1][j] = '2';
						mark(grid, i+1, gridSize, j, gridColSize);
				}
				if (grid[i][j+1] == '1') {
						grid[i][j+1] = '2';
						mark(grid, i, gridSize, j+1, gridColSize);
				}
				if (grid[i][j-1] == '1') {
						grid[i][j-1] = '2';
						mark(grid, i, gridSize, j-1, gridColSize);
				}
				if (grid[i-1][j] == '1') {
						grid[i-1][j] = '2';
						mark(grid, i-1, gridSize, j, gridColSize);
				}

		}

		return 0;
}
int numIslands(char **grid, int gridSize, int *gridColSize)
{
		int count = 0;
		int i,j;
		int flag = 0;
		if (gridSize == 0)
				return 0;
		if (gridSize == 1 && *gridColSize == 1)
				return grid[0][0] == '1';
		if (gridSize == 1) 
		{
				for (j = 0; j < *gridColSize; j++)
						if (grid[0][j] == '1') {
								if (flag == 0)
								{
										count++;
										flag = 1;
								}
						}
						else
								flag = 0;
				return count;
			
		}
		if (*gridColSize == 1)
		{
				for (i = 0; i < gridSize; i++)
						if (grid[i][0] == '1') {
								if (flag == 0)
								{
										count++;
										flag = 1;
								}
						}
						else
								flag = 0;
		return count;
		}
		for (i = 0; i < gridSize; i++)
				for (j = 0; j < *gridColSize; j++)
				{
						if ( grid[i][j] == '1')
						{
								grid[i][j] = '2';
								count++;
								mark(grid, i, gridSize, j, gridColSize);
						}
				}
		return count;
}


