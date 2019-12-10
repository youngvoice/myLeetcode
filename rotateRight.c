/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* rotateRightOneStep(struct ListNode* head){
		struct ListNode *tail, *temp;
		if (head == NULL || head->next == NULL)
				return head;
		temp = head;
		while (temp->next->next != NULL)
				temp = temp->next;
		tail = temp->next;
		tail->next = head;
		head = tail;

		temp->next = NULL;

		return head;
		


}

struct ListNode* rotateRight(struct ListNode* head, int k){
		int i, len = 0;
		struct ListNode *ret = head;
		if (head == NULL || head->next == NULL)
				return head;
		while (ret) {
				len++;
				ret = ret->next;
		}
		ret = head;
		k = k % len;
		for (i = 0; i < k; i++) {
				ret = rotateRightOneStep(ret);
		}
		return ret;


}

