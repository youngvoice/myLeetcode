/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
struct hash_map {
		int val;
		int count;
		UT_hash_handle hh;
};
int* intersect(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize){
		struct hash_map *nums1map = NULL, *nums2map = NULL, *elem, *current, *tmp, *comb = NULL;
		int i = 0, combCount = 0, value = 0;
		int numVal = 0, retSize = 0;
		int *retArray = NULL; 
		for (i = 0; i < nums1Size; i++) {
				value = nums1[i];
				HASH_FIND_INT(nums1map, &value, elem);
				if (elem == NULL) {
						elem = (struct hash_map *)malloc(sizeof(struct hash_map));
						elem->val = value;
						HASH_ADD_INT(nums1map, val, elem);
						elem->count = 0;

				}
				elem->count++; 
		}
		for (i = 0; i < nums2Size; i++) {
				value = nums2[i];
				HASH_FIND_INT(nums2map, &value, elem);
				if (elem == NULL) {
						elem = (struct hash_map *)malloc(sizeof(struct hash_map));
						elem->val = value;
						HASH_ADD_INT(nums2map, val, elem);
						elem->count = 0;

				}
				elem->count++; 
		}
		retSize = 0;
		HASH_ITER(hh, nums1map, current, tmp) {
				value = current->val;
				HASH_FIND_INT(nums2map, &value, elem);
				if (elem != NULL) {
						if (current->count > elem->count)
								combCount = elem->count;
						else
								combCount = current->count;
						elem = (struct hash_map *)malloc(sizeof(struct hash_map));
						elem->val = value;
						HASH_ADD_INT(comb, val, elem);
						elem->count = combCount;
						retSize += combCount;
				}
		}

		retArray = (int *)malloc(retSize*sizeof(int));
		i = 0;
		HASH_ITER(hh, comb, current, tmp) {
				for (int j = 0; j < current->count; j++)
						retArray[i++] = current->val;
				
		}

		*returnSize = retSize;
		return retArray;






		

}

