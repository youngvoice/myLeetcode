/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB) {
		struct ListNode *pA, *pB;
		int flaga, flagb;
		pA = headA;
		pB = headB;
		flaga = flagb = 1;
		if (headA == NULL || headB == NULL)
				return NULL;
		while (1) {

				if (pA == NULL && flaga) {
						flaga = 0;
						pA = headB;
				}
				if (pB == NULL && flagb) {
						flagb = 0;
						pB = headA;
				}

				if (pA == NULL && pB == NULL && flaga == flagb && flaga == 0)
						return NULL;
				if (pA == pB)
						break;
				pA = pA->next;
				pB = pB->next;



		}
		return pA;

    
}
