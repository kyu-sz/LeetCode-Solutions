class Solution(object):
    def uniquePaths(self, m, n):
        """
        :type m: int
        :type n: int
        :rtype: int
        """
        if m > n:
            temp = m
            m = n
            n = temp

        def comb(a, b):
            res = 1
            for i in xrange(a):
                res *= b - i
                res /= 1 + i
            return res

        num_solutions = 0
        for i in xrange(0 if m == 1 else 1, m):
            num_solutions += comb(i, n) * comb(i - 1, m - 2)

        return num_solutions
