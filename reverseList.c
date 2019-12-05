/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* reverseList(struct ListNode* head){
		struct ListNode *pre, *cur, *next;
		if (head == NULL)
				return NULL;
		cur = head;

		next = cur->next;
		while (next) {
				cur->next = next->next;
				next->next = head;
				head = next;

				next = cur->next;
		}

		return head;

}

