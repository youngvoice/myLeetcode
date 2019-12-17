#if 0
#define NUMKEYS (1e6+1)
typedef struct {
		int *hashmap;
    
} MyHashMap;

/** Initialize your data structure here. */

MyHashMap* myHashMapCreate() {
		MyHashMap *obj;
		obj = (MyHashMap *)malloc(sizeof(MyHashMap));
		obj->hashmap = (int *)malloc(NUMKEYS*sizeof(int));
		for (int i = 0; i < NUMKEYS; i++)
				(obj->hashmap)[i] = -1;
		return obj;
    
}

/** value will always be non-negative. */
void myHashMapPut(MyHashMap* obj, int key, int value) {
		(obj->hashmap)[key] = value;
  
}

/** Returns the value to which the specified key is mapped, or -1 if this map contains no mapping for the key */
int myHashMapGet(MyHashMap* obj, int key) {
		return (obj->hashmap)[key];
  
}

/** Removes the mapping of the specified value key if this map contains a mapping for the key */
void myHashMapRemove(MyHashMap* obj, int key) {
		(obj->hashmap)[key] = -1;
  
}

void myHashMapFree(MyHashMap* obj) {
		free(obj->hashmap);
		free(obj);
    
}

/**
 * Your MyHashMap struct will be instantiated and called as such:
 * MyHashMap* obj = myHashMapCreate();
 * myHashMapPut(obj, key, value);
 
 * int param_2 = myHashMapGet(obj, key);
 
 * myHashMapRemove(obj, key);
 
 * myHashMapFree(obj);
*/
#endif

#define NUMKEYS 2011 


struct Node {
		struct Node *next;
		int value;
		int key;
};
typedef struct {
		struct Node *hashArray;
} MyHashMap;

/** Initialize your data structure here. */

MyHashMap* myHashMapCreate() {
		MyHashMap *obj;
		obj = (MyHashMap *)malloc(sizeof(MyHashMap));
		obj->hashArray = (struct Node *)malloc(NUMKEYS*sizeof(struct Node));
		for (int i = 0; i < NUMKEYS; i++) {
				(obj->hashArray+i)->next = NULL;
				(obj->hashArray+i)->value = 0;
				(obj->hashArray+i)->key = 0;

		}
		return obj;
    
}

/** value will always be non-negative. */
void myHashMapPut(MyHashMap* obj, int key, int value) {
		struct Node *head, *cur, *new;
		int found = 0;
		head = obj->hashArray+(key % NUMKEYS);
		cur = head->next;
		while (cur) {
				if (cur->key == key) {
						found = 1;
						break;
				}
				else
						cur = cur->next;

		}
		if (found)
				cur->value = value;
		else {
				new = (struct Node*)malloc(sizeof(struct Node));
				new->value = value;
				new->key = key;
				new->next = head->next;
				head->next = new;
		}



  
}

/** Returns the value to which the specified key is mapped, or -1 if this map contains no mapping for the key */
int myHashMapGet(MyHashMap* obj, int key) {
		struct Node *head, *cur;
		head = obj->hashArray+(key % NUMKEYS);
		cur = head->next;
		while (cur) {
				if (cur->key == key)
						return cur->value;
				else
						cur = cur->next;
		}

		return -1;
  
}

/** Removes the mapping of the specified value key if this map contains a mapping for the key */
void myHashMapRemove(MyHashMap* obj, int key) {
		struct Node *head, *cur;
		head = obj->hashArray+(key % NUMKEYS);
		cur = head->next;
		while (cur) {
				if (cur->key == key) {
						head->next = cur->next;
						free(cur);
						return;
				}
				else {
						head = cur;
						cur = cur->next;
				}
		}
		return;

}

void myHashMapFree(MyHashMap* obj) {
		struct Node *head, *cur, *next;
		for (int i = 0; i < NUMKEYS; i++) {
				head = obj->hashArray+i;
				cur = head->next;
				while (cur) {
						next = cur->next;
						free(cur);
						cur = next;
				}

		}

		free(obj->hashArray);
		free(obj);
    
}

/**
 * Your MyHashMap struct will be instantiated and called as such:
 * MyHashMap* obj = myHashMapCreate();
 * myHashMapPut(obj, key, value);
 
 * int param_2 = myHashMapGet(obj, key);
 
 * myHashMapRemove(obj, key);
 
 * myHashMapFree(obj);
*/
