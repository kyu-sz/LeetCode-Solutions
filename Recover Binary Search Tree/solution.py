class TreeNode(object):
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None


class Solution(object):
    def __init__(self):
        self.first_error = None
        self.second_error = None
        self.last_traversed = None

    def traverse(self, node):
        """
        Traverse the tree and find the two erroneous nodes.
        By pre-order traversal, we expect to find the two swapped nodes that the first one appears greater than the
        following node, then the other one appears less than the previous node.
        A special case is the two swapped elements are adjacent, which requires special treatment.
        :rtype node: TreeNode
        """
        if node.left is not None:
            self.traverse(node.left)

        if self.last_traversed is not None and self.last_traversed.val > node.val:
            if self.first_error is None:
                self.first_error = self.last_traversed
            self.second_error = node

        self.last_traversed = node

        if node.right is not None:
            self.traverse(node.right)

    def recoverTree(self, root):
        """
        :type root: TreeNode
        :rtype: void Do not return anything, modify root in-place instead.
        """
        self.traverse(root)
        temp = self.first_error.val
        self.first_error.val = self.second_error.val
        self.second_error.val = temp
