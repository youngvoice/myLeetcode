/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* removeNthFromEnd(struct ListNode* head, int n){
		struct ListNode *cur, *pre;

		int len = 0;

		cur = head;
		while (cur) {
				len++;
				cur = cur->next;
		}

		n = len - n + 1;

		cur = head;
		pre = NULL;
		while (cur && --n) {
				pre = cur;
				cur = cur->next;
		}

		if (pre == NULL) {
				pre = cur->next;
				free(cur);
				return pre;
		}
		else {
				pre->next = cur->next;
				free(cur);
				return head;
		}






}

