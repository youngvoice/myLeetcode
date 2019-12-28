struct hash_map {
		int val;
		int curIndex;
		int dis;
		UT_hash_handle hh;
};
bool containsNearbyDuplicate(int* nums, int numsSize, int k){
		struct hash_map *myHashMap = NULL, *elem;
		int value, i;
		for (i = 0; i < numsSize; i++) {
				value = nums[i];
				HASH_FIND_INT(myHashMap, &value, elem);
				if (elem == NULL) {
						elem = (struct hash_map *)malloc(sizeof(struct hash_map));
						elem->val = value;
						HASH_ADD_INT(myHashMap, val, elem);
						elem->curIndex = i;
						elem->dis = INT_MAX;
				}
				else {
						if (elem->dis > (i - elem->curIndex))
								elem->dis = i - elem->curIndex;
						if (elem->dis <= k)
								return true;
						elem->curIndex = i;
				}


		}

		return false;


}

