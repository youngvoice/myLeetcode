/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode *detectCycle(struct ListNode *head) {
		struct ListNode *slow, *fast;
		struct ListNode *ptr1 = head;
		struct ListNode *ptr2 = slow;

		if (head == NULL || head->next == NULL || head->next->next == NULL)
				return NULL;
		slow = head;
		fast = head->next->next;
		while (slow != fast) {
				if (slow == NULL || fast == NULL || slow->next == NULL || fast->next == NULL || fast->next->next == NULL)
						return NULL;
				slow = slow->next;
				fast = fast->next->next;
		}
		ptr1 = head;
		ptr2 = slow;

		while (ptr1 != ptr2) {
				ptr1 = ptr1->next;
				ptr2 = ptr2->next;
		}
		return ptr2;





    
}
