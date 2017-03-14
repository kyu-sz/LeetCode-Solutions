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
struct ListNode* swapPairs(struct ListNode* head) {
	if (!head) return NULL;
	if (!head->next) return head;
	struct ListNode *p0 = NULL, *p1 = head, *p2 = head->next, *newHead = head->next;
	while (1) {
		if (p0) p0->next = p2;
		p1->next = p2->next;
		p0 = p2->next = p1;
		p1 = p1->next;
		if (!p1 || !p1->next) break;
		p2 = p1->next;
	}
	return newHead;
}

int main() {
	struct ListNode nodes[4] = {0};
	for (int i = 0; i < 3; ++i) nodes[i].next = nodes + i + 1;
	nodes[0].val = 1;
	nodes[1].val = 2;
	nodes[2].val = 3;
	nodes[3].val = 4;
	struct ListNode* p = swapPairs(nodes);
	while (p) {
		printf("%d ", p->val);
		p = p->next;
	}
	return 0;
}