/**
 * char -> times
 * the record structure can be array or hash_map;
 * */

/*
struct hash_map {
		int c;
		int count;
		int index;

		UT_hash_handle hh;
};
int firstUniqChar(char * s){
		struct hash_map *myHashMap = NULL, *elem, *current, *tmp;
		int val;
		int index, i = 0;
		int min_index = INT_MAX, best_c = -1;

		for (i = 0; (val = s[i]) != '\0'; i++)
		{
				HASH_FIND_INT(myHashMap, &val, elem);
				if (elem == NULL) {
						elem = (struct hash_map*)malloc(sizeof(struct hash_map));
						elem->c = val;
						HASH_ADD_INT(myHashMap, c, elem);
						elem->count = 1;
						elem->index = i;

				}

				else {
						elem->count++;
				}
		}
		
		HASH_ITER(hh, myHashMap, current, tmp) {
				if (current->count == 1) {
						if (min_index > current->index)
						{
								min_index = current->index;
								best_c = current->c;
						}
				}

		}

		HASH_FIND_INT(myHashMap, &best_c, elem);
		if (elem == NULL)
				return -1;
		else
				return min_index;

}

*/


struct hash_map {
		int c;
		int count;

		UT_hash_handle hh;
};

int firstUniqChar(char *s){
		struct hash_map *myHashMap = NULL, *elem;
		int val;
		int i = 0;
		for (i = 0; (val = s[i]) != '\0'; i++)
		{
				HASH_FIND_INT(myHashMap, &val, elem);
				if (elem == NULL) {
						elem = (struct hash_map *)malloc(sizeof(struct hash_map));
						elem->c = val;
						HASH_ADD_INT(myHashMap, c, elem);
						elem->count = 0;
				}
				elem->count++;
		}

		for (i = 0; (val = s[i]) != '\0'; i++)
		{
				HASH_FIND_INT(myHashMap, &val, elem);
				if (elem->count == 1)
						return i;
		}

		return -1;



}
