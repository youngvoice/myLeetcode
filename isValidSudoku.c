struct hash_map {
		int key;
		int count;

		UT_hash_handle hh;
};
bool isValidSudoku(char** board, int boardSize, int* boardColSize){
		struct hash_map *rowHashMap[9] = {NULL}, *colHashMap[9] = {NULL}, *subBoxHashMap[9] = {NULL};
		struct hash_map *rowElem, *colElem, *subBoxElem;
		int i, j, value;
		for (i = 0; i < boardSize; i++)
				for (j = 0; j < *boardColSize; j++)
				{

						value = board[i][j];
						if (value == '.')
								continue;
						else {
								HASH_FIND_INT(rowHashMap[i], &value, rowElem);
								if (rowElem == NULL) {
										rowElem = (struct hash_map *)malloc(sizeof(struct hash_map));
										rowElem->key = value;
										HASH_ADD_INT(rowHashMap[i], key, rowElem);
								}
								else return false;
								HASH_FIND_INT(colHashMap[j], &value, colElem);
								if (colElem == NULL) {
										colElem = (struct hash_map *)malloc(sizeof(struct hash_map));
										colElem->key = value;
										HASH_ADD_INT(colHashMap[j], key, colElem);
								}
								else return false;

								HASH_FIND_INT(subBoxHashMap[(i/3)*3 + j/3], &value, subBoxElem);
								if (subBoxElem == NULL) {
										subBoxElem = (struct hash_map *)malloc(sizeof(struct hash_map));
										subBoxElem->key = value;
										HASH_ADD_INT(subBoxHashMap[(i/3)*3 + j/3], key, subBoxElem);
								}
								else return false;

						}
				}

		return true;


}
