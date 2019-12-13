/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode* rotateRight(struct ListNode* head, int k){
		struct ListNode *t, *tail;
		if (head == NULL || head->next == NULL)
				return head;
		int len = 0;
		t = head;
		while (t) {
				len++;
				tail = t;
				t = t->next;
		}

		tail->next = head;
		k = k % len;

		for (int i = 0; i < len - k - 1; i++)
				head = head->next;
		tail = head;
		head = tail->next;
		tail->next = NULL;;
		return head;

}

