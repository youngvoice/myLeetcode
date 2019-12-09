/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

/*
// first go through the list and create a reverse list
// second compare the half number of the two list
bool isPalindrome(struct ListNode* head){
		struct ListNode *buffer, *cur, *t;
		int ct = 0, len = 0;
		cur = head;

		buffer = NULL;
		while (cur) {
				len++;
				t = (struct ListNode *)malloc(sizeof(struct ListNode));
				t->next = buffer;
				t->val = cur->val;
				buffer = t;
				cur = cur->next;
		}

		if (len % 2 == 0) {
				ct = len / 2;
		}
		else
				ct = (len - 1) / 2;
		cur = head;
		for (int i = 0; i < ct; i++) {
				if (buffer->val != cur->val)
						return false;
				buffer = buffer->next;
				cur = cur->next;

		}
		return true;

}

*/
bool isPalindrome(struct ListNode* head) {
		struct ListNode *slow, *fast, *temp;
		struct ListNode *pre_head = NULL;
		slow = head;
		fast = head;

		if (head == NULL || head->next == NULL)
				return true;
		while (fast != NULL && fast->next != NULL) {
				temp = slow;
				slow = slow->next;
				fast = fast->next->next;
				temp->next = pre_head;
				pre_head = temp;

		}
		if (fast == NULL)
				;
		else
				slow = slow->next;

		while (slow) {
				if (slow->val != pre_head->val)
						return false;
				slow = slow->next;
				pre_head = pre_head->next;
		}

		return true;
}
