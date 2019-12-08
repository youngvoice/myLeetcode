/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* oddEvenList(struct ListNode* head){
		struct ListNode *odd_head, *even_head, *odd, *even;
		struct ListNode *cur;
		int flag = 1;

		cur = head;
		if (cur != NULL) {
				odd_head = cur;
				odd = cur;
				cur = cur->next;
		}

		if (cur != NULL) {
				even_head = cur;
				even = cur;
				cur = cur->next;
		}

		if (cur != NULL) {
				while (cur != NULL) {
						if (flag) {
								odd->next = cur;
								odd = odd->next;
								cur = cur->next;
								flag = !flag;
						}
						else {
								even->next = cur;
								even = even->next;
								cur = cur->next;
								flag = !flag;
						}
				}

				even->next = NULL;
				odd->next = even_head;
		}
		return odd_head;

}

