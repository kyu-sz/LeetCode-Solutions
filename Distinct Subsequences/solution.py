class Solution(object):
    def numDistinct(self, s, t):
        """
        :type s: str
        :type t: str
        :rtype: int
        """
        t_len = len(t)
        num_solutions = [0] * (t_len + 1)
        num_solutions[0] = 1
        for c in s:
            for i in xrange(t_len):
                if t[i] == c:
                    num_solutions[i + 1] += num_solutions[i]

        return num_solutions[t_len]
