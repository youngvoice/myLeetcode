/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


bool isPalindrome(struct ListNode* head){
		int len = 0;
		int mid, mid_left, mid_right;
		struct ListNode *cur = head;
		struct ListNode *mid_leftp, *mid_rightp;
		int i;
		if (cur == NULL)
				return true;
		while (cur) {
				len++;
				cur = cur->next;
		}


		mid = len % 2;
		if (mid == 0) {
				mid_left = len / 2;
				mid_right = mid_left + 1;
		}
		else {
				mid_left = len / 2;
				mid_right = mid_left + 2;
		}

		cur = head;
		i = 0;
		while (cur) {
				i++;
				if (i == mid_right) {
						mid_rightp = cur;
						break;
				}
				cur = cur->next;
		}
		mid_leftp = head;

		while (mid_rightp) {
				if (mid_leftp->val != mid_rightp->val)
						return false;
				mid_rightp = mid_rightp->next;
				mid_leftp = mid_leftp->next;
		}
		return true;


}

