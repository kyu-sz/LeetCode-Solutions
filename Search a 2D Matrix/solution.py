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
        right = m - 1
        while left < right:
            mid = (left + right + 1) >> 1
            if matrix[mid][0] > target:
                right = mid - 1
            elif matrix[mid][0] < target:
                left = mid
            else:
                return True
        if matrix[left][0] == target:
            return True
        line = left
        left = 0
        right = n - 1
        while left < right:
            mid = (left + right + 1) >> 1
            if matrix[line][mid] > target:
                right = mid - 1
            elif matrix[line][mid] < target:
                left = mid
            else:
                return True
        return matrix[line][left] == target
