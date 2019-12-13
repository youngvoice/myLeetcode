/* array + linklist */
#define NUMKEYS 1000

struct Node {
		int val;
		struct Node *next;
};
/*
typedef struct {
		struct Node *HashArray[NUMKEYS];
    
} MyHashSet;
*/

typedef struct {
		struct Node **HashArray;
    
} MyHashSet;


/** Initialize your data structure here. */

MyHashSet* myHashSetCreate() {
		MyHashSet *ret;
		ret = (MyHashSet *)malloc(sizeof(MyHashSet));
		ret->HashArray = (struct Node *)malloc(NUMKEYS*sizeof(struct Node *));
		for (int i = 0; i < NUMKEYS; i++) {
				(ret->HashArray)[i] = NULL;
		}
		return ret;
    
}

void myHashSetAdd(MyHashSet* obj, int key) {
		int index;
		struct Node *cur, *next, *new;
		index = key % NUMKEYS;
		cur = (obj->HashArray)[index];
		new = (struct Node*)malloc(sizeof(struct Node));
		new->val = key;
		new->next = next;
		


		next = cur->next;
		new = (struct Node*)malloc(sizeof(struct Node));
		new->val = key;
		new->next = next;
		cur->next = new;
  
}

void myHashSetRemove(MyHashSet* obj, int key) {
		int index;
		struct Node *cur, *pre;
		index = key % NUMKEYS;
		pre = (obj->HashArray)+index;
		cur = pre->next;
		while (cur) {
				if (cur->val == key) {
						pre->next = cur->next;
						free(cur);
						cur = NULL;
						cur = pre->next;
				}
				else {
						pre = cur;
						cur = pre->next;
				}
		}
}

/** Returns true if this set contains the specified element */
bool myHashSetContains(MyHashSet* obj, int key) {
		int index;
		struct Node *cur;
		index = key % NUMKEYS;
		cur = (obj->HashArray)+index;
		cur = cur->next;
		while (cur) {
				if (cur->val == key)
						return true;
				cur = cur->next;
		}
		return false;
  
}

void myHashSetFree(MyHashSet* obj) {

		struct Node *cur, *next;
		for (int i = 0; i < NUMKEYS; i++) {
				cur = (obj->HashArray) + i;
				cur = cur->next;
				while (cur) {
						next = cur->next;
						free(cur);
						cur = next;
				}

		}

		free(obj->HashArray);
		//free(obj);


    
}

/**
 * Your MyHashSet struct will be instantiated and called as such:
 * MyHashSet* obj = myHashSetCreate();
 * myHashSetAdd(obj, key);
 
 * myHashSetRemove(obj, key);
 
 * bool param_3 = myHashSetContains(obj, key);
 
 * myHashSetFree(obj);
*/


