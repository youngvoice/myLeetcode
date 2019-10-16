/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2){
		struct ListNode *l3, *p;
		l3 = p = NULL;
		int carry = 0;

		while (l1 && l2) {
				if (!p) {
						p = (struct ListNode*)malloc(sizeof(struct ListNode));
						p->next = NULL;
						l3 = p;
				}
				else {
						p->next = (struct ListNode*)malloc(sizeof(struct ListNode));
						p->next->next = NULL;
						p = p->next;
				}

				p->val = l1->val + l2->val + carry;
				carry = 0;
				if (p->val >= 10) {
						carry = p->val / 10;
						p->val = p->val % 10;
				}


				l1 = l1->next;
				l2 = l2->next;
		}
		while (l2) {
				if (!p) {
						p = (struct ListNode*)malloc(sizeof(struct ListNode));
						p->next = NULL;
						l3 = p;
				}
				else {
						p->next = (struct ListNode*)malloc(sizeof(struct ListNode));
						p->next->next = NULL;
						p = p->next;
				}

				p->val = l2->val + carry;
				carry = 0;
				if (p->val >= 10) {
						carry = p->val / 10;
						p->val = p->val % 10;
				}


				l2 = l2->next;

		}

		while (l1) {
				if (!p) {
						p = (struct ListNode*)malloc(sizeof(struct ListNode));
						p->next = NULL;
						l3 = p;
				}
				else {
						p->next = (struct ListNode*)malloc(sizeof(struct ListNode));
						p->next->next = NULL;
						p = p->next;
				}

				p->val = l1->val + carry;
				carry = 0;
				if (p->val >= 10) {
						carry = p->val / 10;
						p->val = p->val % 10;
				}


				l1 = l1->next;

		}

		if (carry != 0) {
				if (!p) {
						p = (struct ListNode*)malloc(sizeof(struct ListNode));
						p->next = NULL;
						l3 = p;
				}
				else {
						p->next = (struct ListNode*)malloc(sizeof(struct ListNode));
						p->next->next = NULL;
						p = p->next;
				}

				p->val = carry;
		}

		return l3;
}
