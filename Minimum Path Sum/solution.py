class Solution(object):
    def minPathSum(self, grid):
        """
        :type grid: List[List[int]]
        :rtype: int
        """
        m = len(grid)
        if m == 0:
            return 0
        n = len(grid[0])
        if n == 0:
            return 0

        for i in xrange(1, n):
            grid[0][i] += grid[0][i - 1]
        for i in xrange(1, m):
            grid[i][0] += grid[i - 1][0]
            for j in xrange(1, n):
                grid[i][j] += min(grid[i][j - 1], grid[i - 1][j])

        return grid[m - 1][n - 1]
