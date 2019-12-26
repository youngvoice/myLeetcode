/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
#define STRLEN 31
struct hash_map {
		int index;
		char key[STRLEN];
		UT_hash_handle hh;
};

struct hash_map_pair {
		int index1;
		int index2;
		UT_hash_handle hh;
};
char ** findRestaurant(char ** list1, int list1Size, char ** list2, int list2Size, int* returnSize){
		struct hash_map *myHashMap1 = NULL, *s;
		struct hash_map_pair *myHashMap2 = NULL, *t, *current, *tmp;
		int index_min = 10000;
		int num;

		int i;
		char *key;
		char **ret;
		for (i = 0; i < list1Size; i++)
		{
				key = list1[i];
				s = (struct hash_map *)malloc(sizeof(struct hash_map));
				strcpy(s->key, key);
				HASH_ADD_STR(myHashMap1, key, s);
				s->index = i;
		}

		for (i = 0; i < list2Size; i++) {
				key = list2[i];
		/**
		 * Here are still some improvement to make, such as record the min sum.
		 * */
				HASH_FIND_STR(myHashMap1, key, s);
				if (s != NULL) {
						t = (struct hash_map_pair *)malloc(sizeof(struct hash_map_pair));
						t->index1 = s->index;
						t->index2 = i;
						HASH_ADD_INT(myHashMap2, index1, t);
				}
		}

		HASH_ITER(hh, myHashMap2, current, tmp) {
				if (index_min > (current->index1 + current->index2))
						index_min = current->index1 + current->index2;
		}
		HASH_ITER(hh, myHashMap2, current, tmp) {
				if (index_min != (current->index1 + current->index2)) {
						HASH_DEL(myHashMap2, current);
						free(current);
				}
		}

		num = HASH_COUNT(myHashMap2);

		ret = (char **)malloc(num*sizeof(char *));

		i = 0;
		HASH_ITER(hh, myHashMap2, current, tmp) {
				ret[i] = (char *)malloc((strlen(list1[current->index1]) + 1)*sizeof(char));
				
				strcpy(ret[i], list1[current->index1]);
				i++;
		}

		*returnSize = num;
		return ret;


}

