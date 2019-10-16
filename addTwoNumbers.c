/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2){
        
        struct ListNode* l3 = (struct ListNode*)malloc(sizeof(struct ListNode));
        struct ListNode *p;
        int carry = 0;
        p = l3;
        l3->next = NULL;       
        l3->val = l1->val + l2->val;
        if (p->val >= 10) {
                carry = p->val/10;
                p->val = p->val%10;
            }

        
        while (l1->next != NULL && l2->next != NULL)
        {
            l1 = l1->next;
            l2 = l2->next;
            p->next = (struct ListNode*)malloc(sizeof(struct ListNode));
            p = p->next;
            p->next = NULL;
            p->val = l1->val + l2->val + carry;
            carry = 0;
            if (p->val >= 10) {
                carry = p->val/10;
                p->val = p->val%10;
            }
        }
        if (l1->next != NULL)
        while (l1->next != NULL)
        {
            l1 = l1->next;
            p->next = (struct ListNode*)malloc(sizeof(struct ListNode));
            p = p->next;
            p->next = NULL;
            p->val = l1->val + carry;
            carry = 0;
            if (p->val >= 10) {
                carry = p->val/10;
                p->val = p->val%10;
            }

        }
        if (l2->next != NULL)
        while (l2->next != NULL)
        {
            l2 = l2->next;
            p->next = (struct ListNode*)malloc(sizeof(struct ListNode));
            p = p->next;
            p->next = NULL;
            p->val = l2->val + carry;
            carry = 0;
            if (p->val >= 10) {
                carry = p->val/10;
                p->val = p->val%10;
            }

        }
        if (carry != 0) {
            p->next = (struct ListNode*)malloc(sizeof(struct ListNode));
            p = p->next;
            p->next = NULL;
            p->val = carry;
        }


        return l3;
            
}
