class Solution(object):
    def searchMatrix(self, matrix, target):
        """
        :type matrix: List[List[int]]
        :type target: int
        :rtype: bool
        """
        m = len(matrix)
        if not m:
            return False
        n = len(matrix[0])
        if not n:
            return False

        left = 0
        right = m * n - 1
        while left < right:
            mid = (left + right + 1) >> 1
            if matrix[mid / n][mid % n] > target:
                right = mid - 1
            elif matrix[mid / n][mid % n] < target:
                left = mid
            else:
                return True
        return matrix[left / n][left % n] == target
