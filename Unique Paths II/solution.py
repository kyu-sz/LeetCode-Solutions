class Solution(object):
    def uniquePathsWithObstacles(self, obstacleGrid):
        """
        :type obstacleGrid: List[List[int]]
        :rtype: int
        """
        m = len(obstacleGrid)
        if m == 0:
            return 0
        n = len(obstacleGrid[0])
        if n == 0:
            return 0

        first_obstacle = 0
        while first_obstacle < n and not obstacleGrid[0][first_obstacle]:
            first_obstacle = first_obstacle + 1
        solution_cnt = [1] * first_obstacle + [0] * (n - first_obstacle)
        for i in xrange(1, m):
            if obstacleGrid[i][0]:
                solution_cnt[0] = 0
            for j in xrange(1, n):
                if obstacleGrid[i][j]:
                    solution_cnt[j] = 0
                else:
                    solution_cnt[j] += solution_cnt[j - 1]

        return solution_cnt[n - 1]
