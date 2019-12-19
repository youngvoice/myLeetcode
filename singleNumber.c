struct hashSet {
		int val;
		UT_hash_handle hh;
};
int singleNumber(int* nums, int numsSize){
		struct hashSet *myset = NULL;
		struct hashSet *s;
		int value;
		int i;
		for (i = 0; i < numsSize; i++) {
				value = nums[i];
				HASH_FIND_INT(myset, &value, s);
				if (s == NULL) {
						s = (struct hashSet*)malloc(sizeof(struct hashSet));
						s->val = value;
						HASH_ADD_INT(myset, val, s);
				}
				else {
						HASH_DEL(myset, s);
						free(s);
				}
		}

		return myset->val;

}
