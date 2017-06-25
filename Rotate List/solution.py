# Definition for singly-linked list.
class ListNode(object):
    def __init__(self, x):
        self.val = x
        self.next = None


class Solution(object):
    def rotateRight(self, head, k):
        """
        :type head: ListNode
        :type k: int
        :rtype: ListNode
        """
        if head is None:
            return None

        arr = []
        p = head
        while p is not None:
            arr.append(p)
            p = p.next

        num_nodes = len(arr)
        k = (k + num_nodes - 1) % num_nodes
        if k == num_nodes - 1:
            return head
        arr[num_nodes - k - 2].next = None
        arr[num_nodes - 1].next = arr[0]
        return arr[num_nodes - k - 1]