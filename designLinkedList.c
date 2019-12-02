typedef struct Node{
		int val;
		struct Node *prev;
		struct Node *next;
    
} MyLinkedList;

/** Initialize your data structure here. */

MyLinkedList* myLinkedListCreate() {
		MyLinkedList *ret;
		if ((ret = (MyLinkedList *)malloc(sizeof(struct Node))) == NULL)
				return NULL;
		ret->prev = ret;
		ret->next = ret;
		ret->val = 0;
		return ret;
}
/*
 * the key part of link list -------->>> the node index */
/** Get the value of the index-th node in the linked list. If the index is invalid, return -1. */
int myLinkedListGet(MyLinkedList* obj, int index) {
		int i = -1;
		MyLinkedList *cur;
		cur = obj;
		while (cur = cur->next && ++i < index);
		if (cur == NULL)
				return -1;
		return cur->val;
  
}

/** Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list. */
void myLinkedListAddAtHead(MyLinkedList* obj, int val) {
		MyLinkedList *head = obj->next;
		MyLinkedList *new;
		if ((new = (MyLinkedList *)malloc(sizeof(struct Node))) == NULL)
				;
		new->val = val;
		new->next = head;
		head->prev = new;

		new->prev = obj;
		obj->next = new;
  
}

/** Append a node of value val to the last element of the linked list. */
void myLinkedListAddAtTail(MyLinkedList* obj, int val) {
		MyLinkedList *cur, *prev, *new;
		cur = obj;
		while (cur = cur->next)
				prev = cur;
		if ((new = (MyLinkedList *)malloc(sizeof(struct Node))) == NULL)
				;
		new->val = val;
		new->next = NULL;
		new->prev = prev;
		prev->next = new;
  
}

/** Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted. */
void myLinkedListAddAtIndex(MyLinkedList* obj, int index, int val) {
		int len = 0, i = 0;
		MyLinkedList *cur, *prev, *new;
		cur = obj;
		while (cur = cur->next) {
				len++;
				prev = cur;
		}
		if (index > len)
				return;
		if ((new = (MyLinkedList *)malloc(sizeof(struct Node))) == NULL)
				;
		new->val = val;
		if (index == len) {
				new->next = NULL;
				new->prev = prev;
				prev->next = new;
				return;
		}

		cur = obj;
		i = -1;
		if (index < len) {
				while (cur = cur->next && ++i < index);
				prev = cur->prev;
				new->next = cur;
				cur->prev = new;

				new->prev = prev;
				prev->next = new;
		}
		return;



  
}

/** Delete the index-th node in the linked list, if the index is valid. */
void myLinkedListDeleteAtIndex(MyLinkedList* obj, int index) {
		int len= 0, i;
		MyLinkedList *cur, *prev;
		cur = obj;
		while (cur = cur->next)
				len++;
		if (index >= len)
				return;

		cur = obj;
		i = -1;
		while (cur = cur->next && ++i < index);
		prev = cur->prev;
		prev->next = cur->next;
		cur->next->prev = prev;
		free(cur);
  
}

void myLinkedListFree(MyLinkedList* obj) {
		MyLinkedList *cur, *next;
		while (obj) {
				next = obj->next;
				free(obj);
				obj = next;

		}

    
}

/**
 * Your MyLinkedList struct will be instantiated and called as such:
 * MyLinkedList* obj = myLinkedListCreate();
 * int param_1 = myLinkedListGet(obj, index);
 
 * myLinkedListAddAtHead(obj, val);
 
 * myLinkedListAddAtTail(obj, val);
 
 * myLinkedListAddAtIndex(obj, index, val);
 
 * myLinkedListDeleteAtIndex(obj, index);
 
 * myLinkedListFree(obj);
*/
