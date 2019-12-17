bool containsDuplicate(int* nums, int numsSize){
		struct hash {
				int value;
				UT_hash_handle hh;
		};

		struct hash *hashTable = NULL;
		for (int i = 0; i < numsSize; i++) {
				struct hash *h;
				HASH_FIND_INT(hashTable, nums+i, h);

				if (h)
						return true;
				else {
						h = malloc(sizeof(struct hash));
						h->value = nums[i];
						HASH_ADD_INT(hashTable, value, h);
				}
		}
		return false;

}
