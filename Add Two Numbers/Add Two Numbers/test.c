#include <stdio.h>

struct ListNode {
	int val;
	struct ListNode *next;
};

void delete_list(struct ListNode* node)
{
	if (node->next != NULL)
		delete_list(node->next);
	free(node);
}

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
	int carry = 0;
	struct ListNode *res_node, *res_head;
	struct ListNode *left;

	int sum = l1->val + l2->val;
	l1 = l1->next, l2 = l2->next;

	if (sum >= 10) {
		carry = 1;
		sum -= 10;
	}
	else carry = 0;

	res_head = res_node = (struct ListNode *)malloc(sizeof(struct ListNode));
	res_node->val = sum;

	while (l1 && l2) {
		sum = l1->val + l2->val + carry;
		l1 = l1->next, l2 = l2->next;

		if (sum >= 10) {
			carry = 1;
			sum -= 10;
		}
		else carry = 0;

		res_node = res_node->next = (struct ListNode *)malloc(sizeof(struct ListNode));
		res_node->val = sum;
	}

	if (l1 || l2) {
		left = l1 ? l1 : l2;
		while (left) {
			int sum = left->val + carry;
			left = left->next;
			if (sum >= 10) {
				carry = 1;
				sum -= 10;
			}
			else carry = 0;
			res_node = res_node->next = (struct ListNode *)malloc(sizeof(struct ListNode));
			res_node->val = sum;
		}
	}

	if (carry)
	{
		res_node = res_node->next = (struct ListNode *)malloc(sizeof(struct ListNode));
		res_node->val = carry;
	}

	res_node->next = NULL;

	return res_head;
}

int main()
{
	struct ListNode *l1_head = NULL, *l2_head = NULL;

	l1_head = (struct ListNode *)malloc(sizeof(struct ListNode));
	l1_head->val = 2;
	l1_head->next = (struct ListNode *)malloc(sizeof(struct ListNode));
	l1_head->next->val = 4;
	l1_head->next->next = (struct ListNode *)malloc(sizeof(struct ListNode));
	l1_head->next->next->val = 7;
	l1_head->next->next->next = NULL;

	l2_head = (struct ListNode *)malloc(sizeof(struct ListNode));
	l2_head->val = 5;
	l2_head->next = (struct ListNode *)malloc(sizeof(struct ListNode));
	l2_head->next->val = 6;
	l2_head->next->next = (struct ListNode *)malloc(sizeof(struct ListNode));
	l2_head->next->next->val = 4;
	l2_head->next->next->next = NULL;

	struct ListNode *res_head = addTwoNumbers(l1_head, l2_head);

	printf("%d", res_head->val);
	while (res_head->next != NULL) {
		res_head = res_head->next;
		printf(" -> %d", res_head->val);
	}
	puts("");

	delete_list(l1_head);
	delete_list(l2_head);
	delete_list(res_head);

	return 0;
}