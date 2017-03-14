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
struct ListNode* reverseKGroup(struct ListNode* head, int k) {
	if (!head) return NULL;
	if (k <= 1) return head;
	typedef struct ListNode LNode;
	LNode** buf = (LNode**)malloc((k + 1) * sizeof(LNode*));

	LNode fake;
	fake.next = head;
	buf[0] = &fake;
	LNode* p = head;

	while (1) {
		int kLeft = 1;
		for (int i = 1; i <= k; ++i) {
			if (!p) {
				kLeft = 0;
				break;
			}
			buf[i] = p;
			p = p->next;
		}
		if (!kLeft) break;
		buf[0]->next = buf[k];
		buf[0] = buf[1];
		buf[1]->next = buf[k]->next;
		for (int i = k; i > 1; --i) buf[i]->next = buf[i - 1];
	}

	return fake.next;
}