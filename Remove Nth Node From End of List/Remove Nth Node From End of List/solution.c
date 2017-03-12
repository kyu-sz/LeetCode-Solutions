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
struct ListNode* removeNthFromEnd(struct ListNode* head, int n) {
	struct ListNode *n_1th, *p = head;
	while (n--) p = p->next;
	if (!p) return head->next;
	n_1th = head;
	while (p = p->next) n_1th = n_1th->next;
	n_1th->next = n_1th->next->next;
	return head;
}

int main() {
	for (int n = 1; n <= 5; ++n)
	{
		struct ListNode nodes[5];
		nodes[0].val = 1;
		nodes[1].val = 2;
		nodes[2].val = 3;
		nodes[3].val = 4;
		nodes[4].val = 5;
		for (int i = 0; i < 4; ++i) nodes[i].next = &nodes[i + 1];
		nodes[4].next = NULL;
		struct ListNode* p = removeNthFromEnd(nodes, n);
		printf("%d: ", n);
		while (p) {
			printf("%d ", p->val);
			p = p->next;
		}
		puts("");
	}
	return 0;
}