#include <stdio.h>

struct ListNode {
	int val;
	struct ListNode *next;
};

typedef struct ListNode LNode;

LNode* getNext(LNode** heap, int* pHeapSize) {
	LNode* toAdd = heap[1]->next ? heap[1]->next : heap[(*pHeapSize)--];
	LNode* toRet = heap[1];

	int loc = 1;
	while (1) {
		int left = loc << 1;
		if (left <= *pHeapSize) {
			int right = left | 1;
			if (right <= *pHeapSize) {
				if (heap[left]->val < heap[right]->val) {
					if (toAdd->val > heap[left]->val) {
						heap[loc] = heap[left];
						loc = left;
						continue;
					}
				}
				else {
					if (toAdd->val > heap[right]->val) {
						heap[loc] = heap[right];
						loc = right;
						continue;
					}
				}
			}
			else {
				if (toAdd->val > heap[left]->val) {
					heap[loc] = heap[left];
					loc = left;
					continue;
				}
			}
		}
		heap[loc] = toAdd;
		break;
	}
	return toRet;
}

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* mergeKLists(struct ListNode** lists, int listsSize) {
	if (!listsSize) return NULL;

	int heapSize = 0;
	LNode** heap = (LNode**)malloc((listsSize + 1) * sizeof(LNode*));
	for (int i = 0; i < listsSize; ++i)
		if (lists[i]) {
			int loc = ++heapSize;
			while (1) {
				if (loc != 1 && heap[loc >> 1]->val > lists[i]->val) {
					heap[loc] = heap[loc >> 1];
					loc >>= 1;
				}
				else {
					heap[loc] = lists[i];
					break;
				}
			}
		}

	if (!heapSize) {
		free(heap);
		return NULL;
	}

	LNode* head = getNext(heap, &heapSize);
	LNode* pCur = head;
	while (heapSize)
		pCur = pCur->next = getNext(heap, &heapSize);

	free(heap);

	return head;
}

int main() {
	LNode buf[3][4] = {0};
	buf[0][0].val = 1;
	buf[0][1].val = 5;
	buf[0][2].val = 8;
	buf[0][3].val = 10;
	for (int i = 0; i < 3; ++i) buf[0][i].next = &buf[0][i + 1];

	buf[1][0].val = 2;
	buf[1][1].val = 3;
	buf[1][2].val = 9;
	for (int i = 0; i < 2; ++i) buf[1][i].next = &buf[1][i + 1];

	buf[2][0].val = 4;
	buf[2][1].val = 5;
	buf[2][2].val = 7;
	for (int i = 0; i < 2; ++i) buf[2][i].next = &buf[2][i + 1];

	LNode* lists[3] = { buf[0], buf[1], buf[2] };
	LNode* sorted = mergeKLists(lists, 3);
	while (sorted) {
		printf("%d ", sorted->val);
		sorted = sorted->next;
	}

	return 0;
}