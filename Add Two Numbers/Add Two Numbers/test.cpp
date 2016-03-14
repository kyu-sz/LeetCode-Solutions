#include "Solution.h"

void delete_list(ListNode* node)
{
	if (node->next != nullptr)
		delete_list(node->next);
	delete node;
}

int main()
{
	ListNode *l1_head, *l2_head;

	l1_head = new ListNode(2);
	l1_head->next = new ListNode(4);
	l1_head->next->next = new ListNode(3);

	l2_head = new ListNode(5);
	l2_head->next = new ListNode(6);
	l2_head->next->next = new ListNode(4);

	Solution solution;
	ListNode *res_head = solution.addTwoNumbers(l1_head, l2_head);

	cout << res_head->val;
	while (res_head->next != nullptr) {
		res_head = res_head->next;
		cout << " -> " << res_head->val;
	}
	cout << endl;

	delete_list(l1_head);
	delete_list(l2_head);
	delete_list(res_head);

	return 0;
}