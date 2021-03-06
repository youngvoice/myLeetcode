/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
bool hasCycle(struct ListNode *head) {
		struct ListNode *slow, *fast;
    
		if (head == NULL || head->next == NULL)
				return false;
		/*
		slow = head->next;
		fast = head;
		*/
		slow = head;
		fast = head->next;
		while (slow != fast) {
				if (slow == NULL || fast == NULL || slow->next == NULL || fast->next == NULL || fast->next->next == NULL)
						return false;

				slow = slow->next;
				fast = fast->next->next;
		}
		return true;
}
