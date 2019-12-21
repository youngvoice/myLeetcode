/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
/*
int* twoSum(int* nums, int numsSize, int target, int* returnSize){
		int i,j;
		int *indices;
		int diff;
		indices =(int *)malloc(2*sizeof(int));
		for (i = 0; i < (numsSize - 1); i++) {
				diff = target - nums[i];
				indices[0] = i;
				for (j = i+1; j < numsSize; j++) {
						indices[1] = j;
						if (nums[j] == diff) {
								*returnSize = 2;
								return indices;
						}
						else
								continue;
				}
				
		}
		*returnSize = 0;
		return NULL;
}
*/



/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
struct hash_map {
		int key;
		int index;
		UT_hash_handle hh;
};
int* twoSum(int* nums, int numsSize, int target, int* returnSize){
		struct hash_map *myHashMap = NULL, *s;
		int i, value;
		int *retArr = NULL;
		*returnSize = 0;
		for (i = 0; i < numsSize; i++) {
				value = target - nums[i];
				HASH_FIND_INT(myHashMap, &value, s);
				if (s == NULL) {
						s = (struct hash_map *)malloc(sizeof(struct hash_map));
						s->key = value;
						HASH_ADD_INT(myHashMap, value, s);
						s->index = i;
				}

				else {
						retArr = (int *)malloc(2*sizeof(int));

						retArr[0] = i;
						retArr[1] = s->index;
						*returnSize = 2;
						break;
				}
		}

		return retArr;



}

