/*
struct hash_map {
		int key;
		int value;
		UT_hash_handle hh;
};
bool isIsomorphic(char * s, char * t){
		struct hash_map *myHashMap = NULL, *elem;
		//char schar, tchar, pre_schar, pre_tchar;
		int schar, tchar, pre_schar, pre_tchar;
		char *st, *tt;
		st = s;
		tt = t;
		for (int i = 0; i < 2; i++) {
				if (i == 1)
				{
						// have memory leak 
						HASH_CLEAR(hh, myHashMap);
						st = t;
						tt = s;
				}
				while (*st != '\0') {
						schar = *st;
						tchar = *tt;
						HASH_FIND_INT(myHashMap, &schar, elem);
						if (elem == NULL) {
								elem = (struct hash_map *)malloc(sizeof(struct hash_map));
								elem->key = schar;
								HASH_ADD_INT(myHashMap, key, elem);
								elem->value = tchar;
						}

						else {
								pre_schar = elem->key;
								pre_tchar = elem->value;
								if (tchar != pre_tchar)
										return false;

						}



						st++;
						tt++;
				}
		}
		return true;

}

*/

/* hash_map + set*/
struct hash_map {
		int key;
		int value;
		UT_hash_handle hh;
};
struct hash_set {
		int key;
		UT_hash_handle hh;
};
bool isIsomorphic(char * s, char * t){
		struct hash_map *myHashMap = NULL, *hashMapElem;
		struct hash_set *myHashSet = NULL, *hashSetElem;
		int schar, tchar, pre_schar, pre_tchar;

		while (*s != '\0') {
				schar = *s;
				tchar = *t;

				HASH_FIND_INT(myHashMap, &schar, hashMapElem);
				if (hashMapElem == NULL) {
						// insert
						HASH_FIND_INT(myHashSet, &tchar, hashSetElem);
						if (hashSetElem == NULL) {
								hashMapElem = (struct hash_map *)malloc(sizeof(struct hash_map));
								hashMapElem->key = schar;
								HASH_ADD_INT(myHashMap, key, hashMapElem);
								hashMapElem->value = tchar;



								hashSetElem = (struct hash_set *)malloc(sizeof(struct hash_set));
								hashSetElem->key = tchar;
								HASH_ADD_INT(myHashSet, key, hashSetElem);

						}
						else
						{
								return false;
						}


				}
				else {
						// judge
						pre_schar = hashMapElem->key;
						pre_tchar = hashMapElem->value;
						if (pre_tchar != tchar)
								return false;

				}

				s++;
				t++;

		}
		return true;

}
