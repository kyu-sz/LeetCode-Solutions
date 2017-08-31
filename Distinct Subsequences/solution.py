class Solution(object):
    def numDistinct(self, s, t):
        """
        :type s: str
        :type t: str
        :rtype: int
        """
        t_len = len(t)
        s_len = len(s)
        dp = [0] * (s_len + 1)
        cnt = 1
        for c in t:
            for i in xrange(s_len):
                tmp = dp[i]
                dp[i] = cnt if s[i] == c else 0
                cnt += tmp
            cnt = 0

        return sum(dp)

if __name__ == "__main__":
    print Solution().numDistinct("rabbbit", "rabbit")
    print Solution().numDistinct("", "a")