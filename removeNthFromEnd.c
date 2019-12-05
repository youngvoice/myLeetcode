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

		n = len - n;

		if (n == 0) {
				cur = head->next;
				free(head);
				return cur;
		}
				
		pre = head;
		while (pre && --n)
				pre = pre->next;

		cur = pre->next; 
		pre->next = cur->next;
		free(cur);
		return head;

}

