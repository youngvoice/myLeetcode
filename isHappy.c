struct hashset {
		int key;
		UT_hash_handle hh;
};
int getSqueareNumber(int n) {
    int num = 0;
    while (n) {
        int tmp = n % 10;
        num += tmp * tmp;
        n = n / 10;
    }
    return num;
}


bool isHappy(int n){
		struct hashset *myhashset = NULL, *s, *current_myhash, *tmp;
		while (1) {
				if (n == 1) {
						HASH_ITER(hh, myhashset, current_myhash, tmp) {
								HASH_DEL(myhashset, current_myhash);
								free(current_myhash);
						}
						return true;
				}
				else {
						HASH_FIND_INT(myhashset, &n, s);
						if (s == NULL) {
								s = (struct hashset*)malloc(sizeof(struct hashset));
								s->key = n;
								HASH_ADD_INT(myhashset, key, s);
								n = getSqueareNumber(n);
						}
						else {
								HASH_ITER(hh, myhashset, current_myhash, tmp) {
										HASH_DEL(myhashset, current_myhash);
										free(current_myhash);
								}
								return false;
						}
				}
		}


		

}

