/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2){
		struct ListNode *l3_head, *l3_cur;
		if (l1 != NULL && l2 != NULL) {
				if (l1->val < l2->val) {
						l3_cur = l1;
						l3_head = l1;
						l1 = l1->next;
				}
				else {
						l3_cur = l2;
						l3_head = l2;
						l2 = l2->next;
				}
		}
		else if (l1 != NULL && l2 == NULL) {
				l3_head = l3_cur = l1;
				l1 = NULL;
		}
		else if (l1 == NULL && l2 != NULL) {
				l3_head = l3_cur = l2;
				l2 = NULL;
		}
		else return NULL;

		while (l1 != NULL && l2 != NULL) {
				if (l1->val < l2->val) {
						l3_cur->next = l1;
						l3_cur = l1;
						l1 = l1->next;
				}
				else {
						l3_cur->next = l2;
						l3_cur = l2;
						l2 = l2->next;
				}
		}

		if (l1 != NULL) {
				l3_cur->next = l1;
		}
		else if(l2 != NULL)
				l3_cur->next = l2;
		else;
		return l3_head;

}

