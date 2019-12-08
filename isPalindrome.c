/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


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

