/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
struct my_hash {
		int key;
		UT_hash_handle hh;
};
int* intersection(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize){
		struct my_hash *hashset = NULL, *hashsetres = NULL, *s, *currenthashsetres, *tmp;
		int i, value, count;
		int *ret;

		for (i = 0; i < nums1Size; i++) {
				value = nums1[i];
				HASH_FIND_INT(hashset, &value, s);
				if (s == NULL) {
						s = (struct my_hash *)malloc(sizeof(struct my_hash));
						s->key = value;
						HASH_ADD_INT(hashset, key, s);
				}
						
		}


		for (i = 0; i < nums2Size; i++) {
				value = nums2[i];
				HASH_FIND_INT(hashset, &value, s);
				if (s != NULL) {
						HASH_FIND_INT(hashsetres, &value, s);
						if (s == NULL) {
								s = (struct my_hash *)malloc(sizeof(struct my_hash));
								s->key = value;
								HASH_ADD_INT(hashsetres, key, s);
						}
				}
		}

		count = HASH_COUNT(hashsetres);
		ret = (int *)malloc(count*sizeof(int));
		i = 0;

		HASH_ITER(hh, hashsetres, currenthashsetres, tmp) {
				ret[i] = currenthashsetres->key;
				i = i+1;
				HASH_DEL(hashsetres, currenthashsetres);
				free(currenthashsetres);
				
		}

		*returnSize = i;
		return ret;


}

