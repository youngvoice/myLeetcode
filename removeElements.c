/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* removeElements(struct ListNode* head, int val){
		struct ListNode *cur, *next;
		cur = head;
		while (cur != NULL && cur->val == val) {
				next = cur->next;
				free(cur);
				cur = next;
				head = cur;
		}
		if (head == NULL)
				return NULL;

		next = cur->next;
		while (next != NULL) {
				if (next->val == val) {
						cur->next = next->next;
						free(next);
						next = cur->next;
				}
				else {
						cur = next;
						next = next->next;
				}
		}
		return head;



}

