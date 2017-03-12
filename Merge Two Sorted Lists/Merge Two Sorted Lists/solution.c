#include <stdio.h>

struct ListNode {
	int val;
	struct ListNode *next;
};

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2) {
	if (l1 && l2) {
		struct ListNode* head;
		if (l1->val < l2->val) {
			head = l1;
			l1 = l1->next;
		}
		else {
			head = l2;
			l2 = l2->next;
		}
		struct ListNode* p = head;
		while (l1 && l2) {
			if (l1->val < l2->val) {
				p = p->next = l1;
				l1 = l1->next;
			}
			else {
				p = p->next = l2;
				l2 = l2->next;
			}
		}
		if (l1) p->next = l1;
		if (l2) p->next = l2;
		return head;
	}
	else return l1 ? l1 : l2;
}