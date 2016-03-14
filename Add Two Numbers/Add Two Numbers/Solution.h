#pragma once

#include <iostream>

using std::cout;
using std::endl;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
	inline int getVal(ListNode*& node) {
		if (node) {
			int res = node->val;
			node = node->next;
			return res;
		}
		else
			return 0;
	}
public:
	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
		int carry = 0;
		ListNode *res_node, *res_head;

		int sum = getVal(l1) + getVal(l2) + carry;
		if (sum >= 10) {
			carry = 1;
			sum -= 10;
		}
		else carry = 0;
		res_head = res_node = new ListNode(sum);

		while (l1 || l2) {
			int sum = getVal(l1) + getVal(l2) + carry;
			if (sum >= 10) {
				carry = 1;
				sum -= 10;
			}
			else carry = 0;
			res_node = res_node->next = new ListNode(sum);
		}

		if (carry)
			res_node = res_node->next = new ListNode(carry);

		return res_head;
	}
};