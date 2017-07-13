class Solution(object):
    def setZeroes(self, matrix):
        """
        :type matrix: List[List[int]]
        :rtype: void Do not return anything, modify matrix in-place instead.
        """
        m = len(matrix)
        if m > 0:
            n = len(matrix[0])
            col0 = False
            for i in xrange(m):
                if not matrix[i][0]:
                    col0 = True
                for j in xrange(1, n):
                    if not matrix[i][j]:
                        matrix[i][0] = matrix[0][j] = 0
            for i in reversed(xrange(m)):
                for j in reversed(xrange(1, n)):
                    if not matrix[i][0] or not matrix[0][j]:
                        matrix[i][j] = 0
            if col0:
                for i in xrange(m):
                    matrix[i][0] = 0

if __name__ == "__main__":
    matrix = [[0,0,0,5],[4,3,1,4],[0,1,1,4],[1,2,1,3],[0,0,1,1]]
    Solution().setZeroes(matrix)
    print matrix
